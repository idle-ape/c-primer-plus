FROM alpine as certs
RUN apk update && apk add ca-certificates

FROM golang:1.24 as builder
WORKDIR /usr/src/app
COPY . .
RUN go build -v -o ./nginx-search-tool ./...

FROM busybox:latest
WORKDIR /usr/src/app
RUN mkdir bin
COPY --from=certs /etc/ssl/certs /etc/ssl/certs
COPY --from=builder /usr/src/app/nginx-search-tool bin/
COPY ./static ./static
COPY ./data ./data
CMD ["./bin/nginx-search-tool"]
