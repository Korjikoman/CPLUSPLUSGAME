#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Player.h"

class Multiplayer {
private:
    std::vector<Player> players;  // Массив игроков
    std::vector<std::string> players_name;  // Массив имен игроков

public:
    // Метод для добавления игрока
    void addPlayer(Player& player);

    // Метод для вывода всех имен игроков
    void printPlayers();

    // Метод для вывода информации о всех игроках
    void printAllPlayers();
};