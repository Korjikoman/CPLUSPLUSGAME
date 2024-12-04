#include "Exceptions.h"


int safeInt(int min, int max) {
    int input;

    while (true) {
        try {
            std::cout << " (enter an integer between " << min << " and " << max << "):  ";
            std::cin >> input;

            // �������� �� ���������� �����
            if (std::cin.fail()) {
                // ���� ��������� ������ ����� (�� �����)
                std::cin.clear(); // ������� ���� ������
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ����� �����
                throw InvalidInputException("Invalid input. Please enter a valid integer.");
            }

            // �������� �� ��������
            if (input < min || input > max) {
                throw InvalidInputException("Input out of range. Please enter a number within the range.");
            }

            return input; // ���� ��� �������� ��������, ���������� �����

        }
        catch (const InvalidInputException& e) {
            // ��������� ����������: ������� ��������� �� ������
            std::cout << e.what() << std::endl;
        }
    }
}

// ������� ��� �������� ������������ ����� ������
std::string safeString(int maxLength = 100) {
    std::string input;

    while (true) {
        try {
            std::getline(std::cin, input);

            // �������� �� ������ ������
            if (input.empty()) {
                throw InvalidInputException("Input cannot be empty. Please enter a valid string.");
            }

            // �������� �� ���������� ������� (����� � �������)
            for (char ch : input) {
                if (!std::isalpha(ch) && !std::isspace(ch)) {
                    throw InvalidInputException("Invalid character in input. Only letters and spaces are allowed.");
                }
            }

            // �������� �� ������������ �����
            if (input.length() > maxLength) {
                throw InvalidInputException("Input is too long. Please enter a string within the allowed length.");
            }

            return input; // ���� ��� �������� ��������, ���������� ������

        }
        catch (const InvalidInputException& e) {
            // ��������� ����������: ������� ��������� �� ������
            std::cout << e.what() << std::endl;
        }
    }
}