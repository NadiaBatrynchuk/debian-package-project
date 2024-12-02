# Етап 1: Збірка програми
FROM gcc:latest AS builder
WORKDIR /app

# Встановлюємо git
RUN apt-get update && apt-get install -y git

# Клонуємо репозиторій та копіюємо необхідні файли
RUN git clone --branch branchHTTPservMutli https://github.com/NadiaBatrynchuk/debian-package-project.git /repo \
    && cp /repo/main.cpp /repo/FuncA.cpp /repo/FuncA.h .

# Компілюємо програму зі статичним лінкуванням
RUN g++ -o main main.cpp FuncA.cpp -static

# Етап 2: Мінімальний фінальний образ
FROM alpine:latest
WORKDIR /app

# Копіюємо виконуваний файл з етапу збірки
COPY --from=builder /app/main .

# Встановлюємо необхідну бібліотеку
RUN apk add --no-cache libc6-compat

# Запуск програми
CMD ["./main"]

