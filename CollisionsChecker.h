#pragma once
#ifndef COLLISIONSCHECKER_H
#define COLLISIONSCHECKER_H

#include <functional>
#include <vector>
#include "Player.h"

// Шаблонный класс для проверки столкновений
template <typename Object>
class CollisionsChecker {
public:
    // Тип лямбда-выражения для обработки столкновения
    using CollisionHandler = std::function<void(Player&, Object&)>;

    // Конструктор, принимающий игрока, массив указателей на объекты и обработчик столкновения
    CollisionsChecker(Player& player, Object* objects, int count, CollisionHandler handler)
        : player_(player), objects_(objects), count_(count), handler_(handler) {}

    // Метод для проверки столкновений
    void checkCollisions() {
        for (int i = 0; i < count_; ++i) {
            if (player_.getX() == objects_[i].getX() && player_.getY() == objects_[i].getY()) {
                handler_(player_, objects_[i]); // Вызываем обработчик
            }
        }
    }

private:
    Player& player_; // Ссылка на игрока
    Object* objects_; // Массив указателей на объекты
    int count_; // Количество объектов в массиве
    CollisionHandler handler_; // Обработчик столкновения
};

#endif // COLLISIONSCHECKER_H