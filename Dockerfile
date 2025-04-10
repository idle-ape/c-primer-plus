FROM golang:1.24 as builder
WORKDIR /usr/src/app
COPY . .
RUN go build -v -o ./nginx-search-tool ./...

FROM busybox:latest
WORKDIR /usr/src/app
RUN mkdir bin
COPY --from=builder /usr/src/app/nginx-search-tool bin/
COPY ./static ./static
COPY ./data ./data
CMD ["./bin/nginx-search-tool"]
