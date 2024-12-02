# Stage 1: Build
FROM gcc:latest AS builder
WORKDIR /app

# Завантаження файлів з публічного репозиторію GitHub
RUN apt-get update && apt-get install -y git \
    && git clone https://github.com/NadiaBatrynchuk/debian-package-project.git . \
    && git checkout branchHTTPservMutli

# Копіювання файлів з підпапки docker-build
RUN cp ./docker-build/main.cpp . && cp ./docker-build/FuncA.cpp . && cp ./docker-build/FuncA.h .

# Компіляція програми
RUN g++ -o main main.cpp FuncA.cpp -static

# Stage 2: Minimal Final Image
FROM alpine:latest
WORKDIR /app

# Копіювання скомпільованого бінарного файлу з попереднього етапу
COPY --from=builder /app/main .

# Встановлення необхідних бібліотек
RUN apk add --no-cache libstdc++

# Встановлення команди для виконання
CMD ["./main"]


