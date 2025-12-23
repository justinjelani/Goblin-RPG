#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

class Player{
    private:

        string username;
        // Starting Stats
        const int startMaxHealth = 125; const int startHealth = startMaxHealth; const int startHeal = 10; 
        const int maxStamStart = 100; const int startStamReg = 25; const int startStam = maxStamStart;
        const int startMelee = 25; const int startFireball = 45;
        const int startCoins = 0;
        // Player health
        int maxHealth = startMaxHealth; int health = maxHealth; int healing = startHeal; int dmgTaken;
        // Stamina
        int maxStamina = maxStamStart; int stamina = maxStamina; int staminaRegen = startStamReg;
        // Attacks
        int meleeDamage = startMelee; int fireballDmg = startFireball;
        // coins
        int coins = startCoins;
        // Prices
        int startCost1 = 200; int startCost2 = 250; int startCost3 = 300; int startCost4 = 450; int startCost5 = 200;
        int cost1 = startCost1; int cost2 = startCost2; int cost3 = startCost3; int cost4 = startCost4; int cost5 = startCost5;

    public:
        // Username
        string getName();
        void setName(string input);
        // Player health
        int getHealth(); int getMaxHealth(); int heal();
        void healPlayer(); void setHealth(); int takeDmg(int dmgTaken);
        // Player Stamina
        int getStamina(); int getMaxStamina(); void setStamina(); void updateStamina(int Stamina); void increaseStamina();
        // Player Attacks
        int getFireball(); int getDamage();
        // Updating Coins
        int getCoins(); 
        int addCoins(int addCoins); void removeCoins(int removeCoins);
        // Reset player
        void reset();
        // Shop
        void shop();

        void displayStats();
};
