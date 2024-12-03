#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Player.h"

class Multiplayer {
private:
    std::vector<Player> players;  // ������ �������
    std::vector<std::string> players_name;  // ������ ���� �������

public:
    // ����� ��� ���������� ������
    void addPlayer(Player& player);

    // ����� ��� ������ ���� ���� �������
    void printPlayers();

    // ����� ��� ������ ���������� � ���� �������
    void printAllPlayers();
};