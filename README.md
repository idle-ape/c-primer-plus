# nginx-search-tool

A tool that search directive, variable or keyword in nginx document.

# Usage

```
docker build -t nginx-search-tool:latest .

docker run -d --rm --name nginx-search-tool -p 8191:8191 nginx-search-tool:latest
```