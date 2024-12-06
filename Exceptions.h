#pragma once
#include <iostream>
#include <limits>
#include <stdexcept>  // ��� ����������
#include <string>
#include <cctype>  

// ���������������� ���������� ��� ��������� ������ �����
class InvalidInputException : public std::runtime_error {
public:
    InvalidInputException(const std::string& message)
        : std::runtime_error(message) {}
};

int safeInt(int min, int max);

std::string safeString(int maxLength);