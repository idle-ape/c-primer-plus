document.addEventListener('DOMContentLoaded', function () {
    const searchButton = document.getElementById('search-button');
    const searchInput = document.getElementById('search-input');
    const resultsContainer = document.getElementById('results-container');
    const loadingElement = document.querySelector('.loading');
    const searchType = document.getElementById('search-type');
    const nginxVersion = document.getElementById('nginx-version');
    const language = document.getElementById('language');
    const updateBtn = document.getElementById('update-docs-btn');
    const updateStatus = document.getElementById('update-status');
    const lastUpdatedSpan = document.getElementById('last-updated');

    let abortController = null;
    let searchTimeout = null;

    // Initialize last updated time
    function initLastUpdated() {
        const lastUpdated = localStorage.getItem('nginxDocsLastUpdated');
        if (lastUpdated) {
            lastUpdatedSpan.textContent = lastUpdated;
        }
    }

    initLastUpdated();

    async function performSearch(query) {
        if (abortController) {
            abortController.abort();
        }

        if (!query.trim()) {
            resultsContainer.innerHTML = `
                <div class="no-results">
                    <p>Please enter search keywords</p>
                </div>
            `;
            loadingElement.style.display = 'none';
            return;
        }

        abortController = new AbortController();
        loadingElement.style.display = 'block';
        resultsContainer.innerHTML = '';

        try {
            const params = new URLSearchParams({
                q: query,
                type: searchType.value,
                version: nginxVersion.value,
                lang: language.value
            });

            const response = await fetch(`/api/search?${params.toString()}`, {
                signal: abortController.signal
            });

            if (!response.ok) {
                throw new Error(`HTTP error! status: ${response.status}`);
            }

            const results = await response.json();
            displayResults(results);
        } catch (error) {
            if (error.name !== 'AbortError') {
                console.error('Search error:', error);
                resultsContainer.innerHTML = `
                    <div class="no-results">
                        <p>Error during search</p>
                        <p>${error.message || 'Please check your connection and try again'}</p>
                    </div>
                `;
            }
        } finally {
            loadingElement.style.display = 'none';
        }
    }

    function handleSearch() {
        const query = searchInput.value.trim();
        clearTimeout(searchTimeout);
        loadingElement.style.display = 'block';
        resultsContainer.innerHTML = '';
        searchTimeout = setTimeout(() => performSearch(query), 300);
    }

    function displayResults(results) {
        if (!results || results.length === 0) {
            resultsContainer.innerHTML = `
                <div class="no-results">
                    <p>No matching results found</p>
                    <p>Try different keywords or check spelling</p>
                </div>
            `;
            return;
        }

        let html = '';
        results.forEach(result => {
            const title = result.title || 'Untitled';
            const url = result.url || '#';
            const snippet = result.snippet || 'No content preview available';
            const urlObj = new URL(url);
            const displayUrl = urlObj.hostname + urlObj.pathname;

            html += `
                <div class="result-item">
                    <div class="result-title">
                        <a href="${url}" target="_blank" rel="noopener noreferrer">${title}</a>
                    </div>
                    <div class="result-url">
                        <a href="${url}" target="_blank" rel="noopener noreferrer">${displayUrl}</a>
                    </div>
                    <div class="result-snippet">${snippet}</div>
                </div>
            `;
        });

        resultsContainer.innerHTML = html;
    }

    async function updateDocs() {
        updateBtn.disabled = true;
        updateStatus.textContent = 'Updating documentation...';
        updateStatus.style.color = '#666';

        try {
            const response = await fetch('/api/update-docs', {
                method: 'POST'
            });

            if (!response.ok) {
                throw new Error(`Update failed: ${response.status}`);
            }

            const data = await response.json();
            const now = new Date();
            const formattedDate = now.toLocaleString('en-US', {
                year: 'numeric',
                month: '2-digit',
                day: '2-digit',
                hour: '2-digit',
                minute: '2-digit'
            });

            lastUpdatedSpan.textContent = formattedDate;
            localStorage.setItem('nginxDocsLastUpdated', formattedDate);

            updateStatus.textContent = data.message;
            updateStatus.style.color = '#269d3e';

            setTimeout(() => {
                updateStatus.textContent = '';
            }, 5000);

        } catch (error) {
            console.error('Document update failed:', error);
            updateStatus.textContent = error.message;
            updateStatus.style.color = '#d9534f';
        } finally {
            updateBtn.disabled = false;
        }
    }

    // Event listeners
    searchButton.addEventListener('click', handleSearch);
    searchInput.addEventListener('keypress', (e) => {
        if (e.key === 'Enter') handleSearch();
    });
    searchInput.addEventListener('input', handleSearch);
    updateBtn.addEventListener('click', updateDocs);
});