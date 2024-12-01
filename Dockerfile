# Вказуємо базовий образ
# Етап 1: Збірка
FROM gcc:latest AS builder
WORKDIR /app

# Копіюємо всі файли з поточного каталогу в контейнер
COPY . .

# Компілюємо програму
RUN g++ -o main main.cpp FuncA.cpp

# Етап 2: Створення фінального образу
FROM debian:stable-slim
WORKDIR /app

# Копіюємо скомпільований виконуваний файл з етапу збірки
COPY --from=builder /app/main .

# Встановлюємо необхідні залежності для запуску програми
RUN apt-get update && \
    apt-get install -y libstdc++6 && \
    rm -rf /var/lib/apt/lists/*

# Вказуємо команду для запуску програми
CMD ["./main"]




