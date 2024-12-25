# Stage 1: Build
FROM gcc:12 AS builder
WORKDIR /app

# Завантаження файлів з публічного репозиторію GitHub
RUN apt-get update && apt-get install -y --no-install-recommends git \
    && git clone https://github.com/NadiaBatrynchuk/debian-package-project.git

# Встановлення робочої директорії
WORKDIR /app/debian-package-project

# Перехід на необхідну гілку репозиторію
RUN git checkout branchHTTPservMutli

# Копіювання файлів з папки docker-build
COPY ./docker-build/FuncA.cpp ./docker-build/FuncA.h ./docker-build/main.cpp ./

# Компіляція програми
RUN g++ -o HttpServer main.cpp FuncA.cpp -static

# Stage 2: Minimal Final Image
FROM alpine:3.18
WORKDIR /app

RUN apk add --no-cache libstdc++ libc6-compat

COPY --from=builder /app/debian-package-project/build/ ./build/

CMD ["./build/HttpServer"]
