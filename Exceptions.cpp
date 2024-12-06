#include "Exceptions.h"


int safeInt(int min, int max) {
    int input;

    while (true) {
        try {
            std::cout << " (enter an integer between " << min << " and " << max << "):  ";
            std::cin >> input;

            // Проверка на успешность ввода
            if (std::cin.fail()) {
                // Если произошла ошибка ввода (не число)
                std::cin.clear(); // Очищаем флаг ошибки
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер ввода
                throw InvalidInputException("Invalid input. Please enter a valid integer.");
            }

            // Проверка на диапазон
            if (input < min || input > max) {
                throw InvalidInputException("Input out of range. Please enter a number within the range.");
            }

            return input; // Если все проверки пройдены, возвращаем число

        }
        catch (const InvalidInputException& e) {
            // Обработка исключения: выводим сообщение об ошибке
            std::cout << e.what() << std::endl;
        }
    }
}

// Функция для проверки корректности ввода строки
std::string safeString(int maxLength = 100) {
    std::string input;

    while (true) {
        try {
            std::getline(std::cin, input);

            // Проверка на пустую строку
            if (input.empty()) {
                throw InvalidInputException("Input cannot be empty. Please enter a valid string.");
            }

            // Проверка на допустимые символы (буквы и пробелы)
            for (char ch : input) {
                if (!std::isalpha(ch) && !std::isspace(ch)) {
                    throw InvalidInputException("Invalid character in input. Only letters and spaces are allowed.");
                }
            }

            // Проверка на максимальную длину
            if (input.length() > maxLength) {
                throw InvalidInputException("Input is too long. Please enter a string within the allowed length.");
            }

            return input; // Если все проверки пройдены, возвращаем строку

        }
        catch (const InvalidInputException& e) {
            // Обработка исключения: выводим сообщение об ошибке
            std::cout << e.what() << std::endl;
        }
    }
}