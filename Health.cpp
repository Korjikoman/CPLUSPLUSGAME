#include "Health.h"


Health::Health() {
    current_health = max_health;
}

// Static method that changes max_health
void Health::setMaxHealth(int new_size)
{
    max_health = new_size;
}
// Initializing static variable
int Health::max_health = 10;

int Health::getCurrentHealth()
{
    return current_health;
}

int Health::getMaxHealth() { return max_health; }

void Health::heal(int healpoints) {
    current_health += healpoints;
    if (current_health > max_health) {
        current_health = max_health;
    }
}
void Health::changeHealthValue(int new_value) {
    current_health = new_value;
}