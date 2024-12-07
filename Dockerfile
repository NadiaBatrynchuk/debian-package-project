# Stage 1: Build
FROM gcc:12 AS builder
WORKDIR /app

# Завантаження файлів з публічного репозиторію GitHub
RUN apt-get update && apt-get install -y --no-install-recommends git=1:2.25.1-1ubuntu3 \
    && git clone https://github.com/NadiaBatrynchuk/debian-package-project.git \
WORKDIR /app/debian-package-project 
RUN git checkout branchHTTPservMutli

# Копіювання файлів з папки docker-build
COPY ./docker-build/FuncA.cpp ./docker-build/FuncA.h ./docker-build/main.cpp ./

# Компіляція програми
RUN g++ -o main main.cpp FuncA.cpp -static

# Stage 2: Minimal Final Image
FROM alpine:3.18
WORKDIR /app
COPY --from=builder /app/main .
RUN apk add --no-cache libstdc++=10.3.0-r0
CMD ["./main"]

