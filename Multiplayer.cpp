#include "Multiplayer.h"

// ����� ��� ���������� ������
void Multiplayer::addPlayer(Player& player) {
    players.push_back(player);  // ��������� ������ � ������
    players_name.push_back(player.getName());  // ��������� ��� ������ � ������ ����
}

// ����� ��� ������ ���� ���� �������
void Multiplayer::printPlayers()  {
    std::cout << "List of players: " << std::endl;
    for (auto& name : players_name) {
        std::cout << name << std::endl;
    }
}

// ����� ��� ������ ���������� � ���� �������
void Multiplayer::printAllPlayers()  {
    for (auto& player : players) {
        player.printPlayer();
    }
}