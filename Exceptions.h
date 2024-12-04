#pragma once
#include <iostream>
#include <limits>
#include <stdexcept>  // Для исключений
#include <string>
#include <cctype>  

// Пользовательское исключение для обработки ошибок ввода
class InvalidInputException : public std::runtime_error {
public:
    InvalidInputException(const std::string& message)
        : std::runtime_error(message) {}
};

int safeInt(int min, int max);

std::string safeString(int maxLength);