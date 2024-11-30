#include "Health.h"


Health::Health() : current_health(0), max_health(0) {}
Health::Health(int max) {
    current_health = max_health = max;

}

int Health::getCurrentHealth()
{
    return current_health;
}

int Health::getMaxHealth() { return max_health; }
void Health::changeMaxHealthValue(int value) {
    max_health = value;
}
void Health::heal(int healpoints) {
    current_health += healpoints;
    if (current_health > max_health) {
        current_health = max_health;
    }
}
void Health::changeHealthValue(int new_value) {
    current_health = new_value;
}