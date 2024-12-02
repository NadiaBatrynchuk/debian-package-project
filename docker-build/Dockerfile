# Етап 1: Збірка програми
FROM gcc:latest AS builder
WORKDIR /app

# Встановлюємо git
RUN apt-get update && apt-get install -y git

# Клонуємо репозиторій та переміщуємо необхідні файли
RUN git clone --branch branchHTTPservMutli https://github.com/NadiaBatrynchuk/debian-package-project.git /repo \
    && mv /repo/main.cpp /app/ \
    && mv /repo/FuncA.cpp /app/ \
    && mv /repo/FuncA.h /app/

# Компілюємо програму зі статичним лінкуванням
RUN g++ -o main main.cpp FuncA.cpp -static

# Етап 2: Мінімальний фінальний образ
FROM alpine:latest
WORKDIR /app

# Копіюємо виконуваний файл з етапу збірки
COPY --from=builder /app/main .

# Встановлюємо бібліотеку для сумісності
RUN apk add --no-cache libc6-compat

# Запускаємо програму
CMD ["./main"]

