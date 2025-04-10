package main

import (
	"cmp"
	"encoding/json"
	"flag"
	"fmt"
	"log"
	"net/http"
	"runtime"
	"strings"
	"time"

	"github.com/gorilla/mux"
)

// Document is a struct that represents a single documentation entry.
type Document struct {
	ID       string `json:"id"`       // unique identifier
	Title    string `json:"title"`    // directive or variable name
	URL      string `json:"url"`      // anchor URL
	Content  string `json:"content"`  // directive or variable description, etc.
	Type     string `json:"type"`     // directive, variable, example, etc.
	Version  string `json:"version"`  // all, stable, mainline, 1.25, etc.
	Language string `json:"language"` // en, py etc.
}

// generateSnippet generates a snippet of the given content that contains the query.
func generateSnippet(content, query string) string {
	contentLower := strings.ToLower(content)
	queryLower := strings.ToLower(query)

	pos := strings.Index(contentLower, queryLower)
	if pos == -1 {
		return ""
	}

	start := max(0, pos-30)
	end := min(len(content), pos+len(query)+70)

	snippet := content[start:end]
	if start > 0 {
		snippet = "..." + snippet
	}
	if end < len(content) {
		snippet = snippet + "..."
	}

	// highlight the query in the snippet
	snippet = strings.ReplaceAll(snippet, query, "<strong>"+query+"</strong>")
	return snippet
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	url := flag.String("u", "https://nginx.org/en/docs", "Nginx documentation URL")
	file := flag.String("d", "./data/nginx-docs.json", "data file path to store/load documents")
	static := flag.String("s", "./static", "static file directory path")
	addr := flag.String("a", ":8191", "HTTP server port")
	flag.Parse()

	searchService, crawlerService := NewSearchService(), NewCrawler(*url, *file)
	if err := searchService.LoadDocuments(*file); err != nil {
		log.Fatalf("Failed to load documents: %v", err)
	}

	r := mux.NewRouter()

	r.HandleFunc("/api/search", func(w http.ResponseWriter, r *http.Request) {
		query := r.URL.Query().Get("q")
		searchType := cmp.Or(r.URL.Query().Get("type"), "all")
		version := cmp.Or(r.URL.Query().Get("version"), "all")
		language := cmp.Or(r.URL.Query().Get("lang"), "en")

		if query == "" {
			http.Error(w, "Query parameter 'q' is required", http.StatusBadRequest)
			return
		}

		results := searchService.Search(SearchRequest{
			Query:    query,
			Type:     searchType,
			Version:  version,
			Language: language,
		})

		w.Header().Set("Content-Type", "application/json")
		json.NewEncoder(w).Encode(results)
	}).Methods("GET")

	r.HandleFunc("/api/update-docs", func(w http.ResponseWriter, r *http.Request) {
		if r.Method != http.MethodPost {
			http.Error(w, "Method not allowed", http.StatusMethodNotAllowed)
			return
		}

		w.Header().Set("Content-Type", "application/json")
		if err := crawlerService.Update(); err != nil {
			json.NewEncoder(w).Encode(map[string]string{
				"status":  "failed",
				"message": fmt.Errorf("Failed to update documentation: %v", err).Error(),
			})
			return
		}

		// reload documents
		if err := searchService.LoadDocuments(*file); err != nil {
			json.NewEncoder(w).Encode(map[string]string{
				"status":  "failed",
				"message": fmt.Errorf("Failed to load documents: %v", err).Error(),
			})
			return
		}

		json.NewEncoder(w).Encode(map[string]string{
			"status":  "success",
			"message": "Documentation updated successfully!",
		})
	}).Methods("POST")

	r.PathPrefix("/").Handler(http.FileServer(http.Dir(*static)))

	srv := &http.Server{
		Handler:      r,
		Addr:         *addr,
		WriteTimeout: 15 * time.Second,
		ReadTimeout:  15 * time.Second,
	}

	log.Println("Starting server on", *addr)
	runtime.GC()
	log.Fatal(srv.ListenAndServe())
}
