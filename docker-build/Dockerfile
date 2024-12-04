# Stage 1: Build
FROM gcc:latest AS builder
WORKDIR /app

# Завантаження файлів з публічного репозиторію GitHub
RUN apt-get update && apt-get install -y git \
    && git clone https://github.com/NadiaBatrynchuk/debian-package-project.git . \
    && git checkout branchHTTPservMutli

# Копіювання файлів з папки docker-build
COPY ./FuncA.cpp ./FuncA.h ./main.cpp .

# Компіляція програми
RUN g++ -o main main.cpp FuncA.cpp -static

# Stage 2: Minimal Final Image
FROM alpine:latest
WORKDIR /app
COPY --from=builder /app/main .
RUN apk add --no-cache libstdc++
CMD ["./main"]

