#include "Multiplayer.h"

// Метод для добавления игрока
void Multiplayer::addPlayer(Player& player) {
    players.push_back(player);  // Добавляем игрока в массив
    players_name.push_back(player.getName());  // Добавляем имя игрока в массив имен
}

// Метод для вывода всех имен игроков
void Multiplayer::printPlayers()  {
    std::cout << "List of players: " << std::endl;
    for (auto& name : players_name) {
        std::cout << name << std::endl;
    }
}

// Метод для вывода информации о всех игроках
void Multiplayer::printAllPlayers()  {
    for (auto& player : players) {
        player.printPlayer();
    }
}