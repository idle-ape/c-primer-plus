package main

import (
	"encoding/json"
	"fmt"
	"log"
	"os"
	"regexp"
	"strings"

	"github.com/gocolly/colly/v2"
)

// Crawler implements the update logic of nginx doc
type Crawler struct {
	url      string // nginx doc url
	dataFile string // file path to store crawled data
}

func NewCrawler(url, dataFile string) *Crawler {
	return &Crawler{
		url:      url,
		dataFile: dataFile,
	}
}

// Update updates the nginx doc data
func (cl *Crawler) Update() (err error) {
	c := colly.NewCollector(
		colly.AllowedDomains("nginx.org"),
		colly.UserAgent("Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/134.0.0.0 Safari/537.36"),
		colly.MaxDepth(2),
		colly.Async(true),
		colly.URLFilters(
			regexp.MustCompile("https://nginx.org/en/docs.*"),
		),
	)

	c.Limit(&colly.LimitRule{
		Parallelism: 100,
		Delay:       3,
	})

	var documents []Document

	// for index page
	c.OnHTML("div#content ul li a", func(e *colly.HTMLElement) {
		if href := e.Attr("href"); strings.Contains(href, "_module.html") {
			_ = e.Request.Visit(e.Request.AbsoluteURL(href))
		}
	})

	// for directive and variable
	c.OnHTML("div#content", func(e *colly.HTMLElement) {
		// directive
		e.ForEach("div.directive", func(_ int, el *colly.HTMLElement) {
			directive := el.ChildText("strong")
			desc := strings.ReplaceAll(strings.Trim(el.DOM.NextFiltered("p").Text(), "\n"), "\n", " ")
			anchor := fmt.Sprintf("%s#%s", el.Request.URL.String(), directive)
			documents = append(documents, Document{
				ID:       directive,
				Title:    directive,
				URL:      anchor,
				Content:  desc,
				Type:     "directive",
				Version:  "all",
				Language: "en",
			})
		})

		// variable
		e.ForEach("dt[id^='var_']", func(_ int, el *colly.HTMLElement) {
			variable := el.ChildText("code")
			desc := strings.ReplaceAll(strings.Trim(el.DOM.NextFiltered("dd").Text(), "\n"), "\n", " ")
			documents = append(documents, Document{
				ID:       variable,
				Title:    variable,
				URL:      fmt.Sprintf("%s#%s", el.Request.URL.String(), "variables"),
				Content:  desc,
				Type:     "variable",
				Version:  "all",
				Language: "en",
			})
		})
	})

	c.OnRequest(func(r *colly.Request) {
		fmt.Println("Visiting", r.URL.String())
	})

	c.OnError(func(r *colly.Response, e error) {
		err = fmt.Errorf("Request %s failed, status code: %d, error: %v", r.Request.URL, r.StatusCode, e)
		log.Printf("Request %s failed, status code: %d, error: %v", r.Request.URL, r.StatusCode, e)
	})

	if err := c.Visit(cl.url); err != nil {
		return err
	}

	c.Wait()

	if err != nil {
		return err
	}

	// save data to file
	file, err := os.Create(cl.dataFile)
	if err != nil {
		return err
	}
	defer file.Close()

	encoder := json.NewEncoder(file)
	encoder.SetIndent("", "  ")
	err = encoder.Encode(documents)
	if err != nil {
		return err
	}

	fmt.Printf("Successfully scraped %d Nginx directives\n", len(documents))
	fmt.Println("Results saved to nginx_docs.json")

	return nil
}
