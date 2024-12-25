#include <boost/asio.hpp>
#include <iostream>
#include <sstream>
#include "FuncA.h"

using namespace boost::asio;
using ip::tcp;

// Обробник запитів
std::string handle_request()
{
    FuncA funcA;
    std::ostringstream response;

    int n = 10;

    double result = funcA.calculate(n);

    response << "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\n";
    response << "FuncA returns: " << result << "\n";

    return response.str();
}

// Обробник підключення
void handle_client(tcp::socket &socket)
{
    try
    {
        // Читання запиту від клієнта
        boost::asio::streambuf buffer;
        boost::asio::read_until(socket, buffer, "\r\n");

        // Формуємо відповідь
        std::string response = handle_request();

        // Відправляємо відповідь клієнту
        boost::asio::write(socket, boost::asio::buffer(response));

        // Закриваємо з'єднання
        socket.shutdown(tcp::socket::shutdown_both);
        socket.close();
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

int main()
{
    try
    {
        io_service io_service;

        // Налаштовуємо сервер на порт 8080
        tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 8080));
        std::cout << "Server is running on port 8080...\n";

        while (true)
        {
            tcp::socket socket(io_service);
            acceptor.accept(socket);

            handle_client(socket);
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}

