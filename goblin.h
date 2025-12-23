#pragma once
#include <iostream>
#include <cstdlib>

class Goblin{
    int health = 100;
    int maxHealth = 100;
    int baseDamage = 3;
    int damage;
    int dmgTaken;
    
    public:
        int getDamage();
        void increaseDamage();
        void increaseHealth();
        int getHealth();
        int getMaxHealth();
        void resetHealth();
        void reset();
        void takeDmg(int dmgTaken);
};
