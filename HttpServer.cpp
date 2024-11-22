#include <boost/asio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "FuncA.h"

using namespace boost::asio;
using ip::tcp;

// Обробник запитів
std::string handle_request() {
    FuncA funcA;
    std::ostringstream response;

    // Початок вимірювання часу
    auto start = std::chrono::high_resolution_clock::now();

    // Генеруємо масив значень
    const int array_size = 500000; // Налаштуємо розмір масиву
    std::vector<double> values(array_size);
    for (int i = 0; i < array_size; ++i) {
        values[i] = funcA.calculate(i % 10 + 1); // Використовуємо мою функцію
    }

    // Сортуємо масив
    std::sort(values.begin(), values.end());

    // Завершуємо вимірювання часу
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    // Формуємо відповідь
    response << "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\n";
    response << "Elapsed time: " << elapsed << " ms\n";
    response << "Sorted values (first 10):\n";
    for (int i = 0; i < 10; ++i) {
        response << values[i] << "\n";
    }

    return response.str();
}

// Обробник підключення
void handle_client(tcp::socket& socket) {
    try {
        // Читаємо запит від клієнта
        boost::asio::streambuf buffer;
        boost::asio::read_until(socket, buffer, "\r\n");

        // Формуємо відповідь
        std::string response = handle_request();

        // Відправляємо відповідь клієнту
        boost::asio::write(socket, boost::asio::buffer(response));

        // Закриваємо з'єднання
        socket.shutdown(tcp::socket::shutdown_both);
        socket.close();
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

int main() {
    try {
        io_service io_service;

        // Налаштовуємо сервер на порт 8080
        tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 8080));
        std::cout << "Server is running on port 8080...\n";

        while (true) {
            tcp::socket socket(io_service);
            acceptor.accept(socket);

            handle_client(socket);
        }
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}

