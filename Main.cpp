#include "Main.h"


int main()
{
    
    // Инициализируем объекты класса
    
    // initializing map and objects on it
    Map map;
    Player& player = map.getPlayer();


    // Game loop
    bool game_running = true;
    while (game_running && player.getCurrentHealth() > 0) {
        std::cout << "\n\n";
        std::cout << "\n--- Game Menu ---\n";
        std::cout << "1. Move player\n";
        std::cout << "2. Show class objects\n";
        std::cout << "3. Change settings\n";
        std::cout << "4. Exit game\n";
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: // Перемещаем игрока по указанным координатам
            int dx, dy;
            std::cout << "Enter (x,y) to move the player: ";
            std::cin >> dx >> dy;
            map.movePlayer(dx, dy);
            
            map.checkCollisions();
            break;
        case 2:
            // Показываем классы и их характеристику
            map.showInitializedClasses();
            break;
        case 3:
            changeSettings();
            break;
        case 4:
            // Выход из игры
            game_running = false;
            std::cout << "Exiting the game. Goodbye!" << std::endl;
            break;
     
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }


    
    return 0;
}

