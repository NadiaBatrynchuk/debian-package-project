# Вказуємо базовий образ
FROM ubuntu:20.04

# Встановлюємо часову зону, щоб уникнути запитів під час apt-get install
ENV DEBIAN_FRONTEND=noninteractive

# Оновлюємо пакети та встановлюємо необхідні залежності без зайвих додаткових пакетів
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    g++ \
    libboost-all-dev \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Копіюємо проект у контейнер
COPY . /usr/src/app

# Переходимо до каталогу з кодом
WORKDIR /usr/src/app

# Використовуємо cmake для побудови проекту з додаванням pthread
RUN rm -rf build && mkdir build && cd build && cmake .. -DCMAKE_CXX_FLAGS="-pthread" && make

# Вказуємо команду для запуску програми
CMD ["./build/HttpServer"]



