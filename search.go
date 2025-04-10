package main

import (
	"encoding/json"
	"log"
	"os"
	"strings"
	"sync/atomic"
	"unsafe"
)

// SearchResult response for search
type SearchResult struct {
	Title   string `json:"title"`
	URL     string `json:"url"`
	Snippet string `json:"snippet"`
}

// SearchRequest request for search
type SearchRequest struct {
	Query    string `json:"query"`
	Type     string `json:"type"`
	Version  string `json:"version"`
	Language string `json:"language"`
}

// SearchService implements the search service
type SearchService struct {
	documents unsafe.Pointer
}

func NewSearchService() *SearchService {
	return &SearchService{}
}

// LoadDocuments load documents from file
func (s *SearchService) LoadDocuments(filename string) error {
	file, err := os.ReadFile(filename)
	if err != nil {
		return err
	}

	var docs []Document
	if err := json.Unmarshal(file, &docs); err != nil {
		return err
	}

	atomic.CompareAndSwapPointer(&s.documents, nil, unsafe.Pointer(&docs))

	log.Printf("Loaded %d documents\n", len(docs))
	return nil
}

// Search do the search
func (s *SearchService) Search(req SearchRequest) []SearchResult {
	query := strings.ToLower(req.Query)
	var results []SearchResult

	docs := (*[]Document)(atomic.LoadPointer(&s.documents))
	for _, doc := range *docs {
		if req.Type != "all" && doc.Type != req.Type {
			continue
		}
		if req.Version != "all" && doc.Version != req.Version {
			continue
		}
		if req.Language != "all" && doc.Language != req.Language {
			continue
		}

		content := strings.ToLower(doc.Content)
		title := strings.ToLower(doc.Title)
		if strings.Contains(title, query) || strings.Contains(content, query) {
			snippet := generateSnippet(doc.Content, query)
			if len(snippet) == 0 {
				snippet = doc.Content
				if len(snippet) > 150 {
					snippet = snippet[:150] + "..."
				}
			}

			results = append(results, SearchResult{
				Title:   doc.Title,
				URL:     doc.URL,
				Snippet: snippet,
			})
		}
	}

	return results
}
