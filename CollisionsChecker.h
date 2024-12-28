#pragma once
#ifndef COLLISIONSCHECKER_H
#define COLLISIONSCHECKER_H

#include <functional>
#include <vector>
#include "Player.h"

// ��������� ����� ��� �������� ������������
template <typename Object>
class CollisionsChecker {
public:
    // ��� ������-��������� ��� ��������� ������������
    using CollisionHandler = std::function<void(Player&, Object&)>;

    // �����������, ����������� ������, ������ ���������� �� ������� � ���������� ������������
    CollisionsChecker(Player& player, Object* objects, int count, CollisionHandler handler)
        : player_(player), objects_(objects), count_(count), handler_(handler) {}

    // ����� ��� �������� ������������
    void checkCollisions() {
        for (int i = 0; i < count_; ++i) {
            if (player_.getX() == objects_[i].getX() && player_.getY() == objects_[i].getY()) {
                handler_(player_, objects_[i]); // �������� ����������
            }
        }
    }

private:
    Player& player_; // ������ �� ������
    Object* objects_; // ������ ���������� �� �������
    int count_; // ���������� �������� � �������
    CollisionHandler handler_; // ���������� ������������
};

#endif // COLLISIONSCHECKER_H