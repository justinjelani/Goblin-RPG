#include <iostream>
#include <limits>
#include "Player.h"
#include "Goblin.h"
using namespace std;

bool gameRunning = true;
int level = 1;
string input;
void options(Player &p1, Goblin &g);
bool death(Player &p1, Goblin &g);
void game(Player &p1, Goblin &g);

// Introduction to game
int main(){
    srand(static_cast<unsigned int>(time(NULL)));
    Player p1;
    Goblin g;

    cout<< "---- Welcome to Goblin RPG Game! ----" << endl;
    cout<< "[!] Your objective is to beat the goblin before it defeats you!" << endl;
    cout<< "[!] Enter your username: ";
    cin>> input; 
    p1.setName(input);
    input = " ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<< "[!] Alright " << p1.getName() << ", let's do this." << endl;
    cout<< " " << endl;
    game(p1, g);
}

void game(Player &p1, Goblin &g){
    while(gameRunning){
        cout<< "-------------- Level " << level << "--------------"<< endl;
        options(p1, g);
    }
    cout<<"[!] Thanks for playing! Final Stats: " << endl;
    cout<< " "<< endl;
    p1.displayStats();
    cout<< "[!] " << p1.getName() << " was defeated on level " << level << endl;
    cout<<"[!] Enter P to play again, Q to quit."<< endl;
    cin>> input;

    while(input != "P" && input != "Q"){
        cout<< "Invalid input! Please enter either P or Q!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin>> input;
    }
    if(input == "Q"){
        return;
    }
    if (input == "P"){
        level = 1;
        p1.reset();
        g.reset();
        gameRunning = true;
        game(p1, g);
    }
    }

// Display Player Options
void options(Player &p1, Goblin &g){
    int option;
    cout<< "[!] What move would you like to use? " << endl;
    cout<< " " << endl; 
    cout<< "1. Heal"<< endl;
    cout<< "2. Melee"<< endl;
    cout<< "3. Fireball"<< endl;
    cout<< "4. Rest" << endl;
    cout<< "5. Shop" << endl;
    cout<< "6. Display Stats"<< endl;
    cout<< "7. Flee" << endl;
    cin>> option;

    while(option < 1 || option > 7){
        cout<< "Invalid input! Must input a number between 1-7" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin>> option;
    }

//Display the Attack Log
    switch(option){
        case 1:
            cout<< "-------------- Attack Log --------------"<< endl;
            cout<< " " << endl;
            p1.healPlayer();
            if(p1.getStamina() < 12){
                cout<<"[!] Not enough stamina to use this ability." << endl;
                cout<< " " << endl;
                break;
            } else {
                p1.updateStamina(10);
            }
            cout<< "[!] "<< p1.getName() << " gained " << p1.heal() << " HP!" << endl;
            if(p1.getHealth() > p1.getMaxHealth()){
                cout<< "[!] Oops! Max health is " << p1.getMaxHealth() << "." << endl;
                p1.setHealth();
             }
            cout<<"[!] The goblin attacked " << p1.getName() << " and did " << p1.takeDmg(g.getDamage()) << " damage!" << endl;
            if(death (p1, g)){
                return;
            }
            cout<< "[!] Current player HP: " << p1.getHealth() << "/" << p1.getMaxHealth() << endl; 
            cout<< "[!] Current Stamina: " << p1.getStamina() << "/" << p1.getMaxStamina() << endl;
            cout<< "[!] Current Goblin HP: " << g.getHealth() << "/" << g.getMaxHealth() << endl;
            cout<< " " << endl;
            break;
        case 2:
            cout<< "-------------- Attack Log --------------"<< endl;
            cout<< " " << endl;
            if(p1.getStamina() < 15){
                cout<<"[!] Not enough stamina to use this ability." << endl;
                cout<< " " << endl;
                break;
            } else {
                p1.updateStamina(15);
            }
            cout<<"[!] "<< p1.getName() << " attacked and did " << p1.getDamage() << " damage!"<< endl;
            
            g.takeDmg(p1.getDamage());
            if(!death(p1, g)){
            cout<<"[!] The goblin attacked " << p1.getName() << " and did " << p1.takeDmg(g.getDamage()) << " damage!" << endl;
            if(death (p1, g)){
                return;
            }
            cout<< "[!] Player HP: " << p1.getHealth() << "/" << p1.getMaxHealth() << endl; 
            cout<< "[!] Stamina: " << p1.getStamina() << "/" << p1.getMaxStamina() << endl;
            cout<< "[!] Current Goblin HP: " << g.getHealth() << "/" << g.getMaxHealth()<< endl;
            cout<< " " << endl;
            }
            break;
        case 3:
            cout<< "-------------- Attack Log --------------"<< endl;
            cout<< " " << endl;
            if(p1.getStamina() < 25){
                cout<<"[!] Not enough stamina to use this ability." << endl;
                cout<< " " << endl;
                break;
            } else {
                p1.updateStamina(25);
            }
            cout<< "[!] "<< p1.getName() << " used Fireball and it did " << p1.getFireball() << " damage!" << endl; 
            g.takeDmg(p1.getFireball());
            if(!death(p1, g)){
            cout<< "[!] The goblin attacked "<< p1.getName() << " and did " << p1.takeDmg(g.getDamage()) << " damage!"<< endl;
            if(death(p1, g)){
                return;
            }
            cout<< "[!] Player HP: " << p1.getHealth() <<  "/" << p1.getMaxHealth() << endl; 
            cout<< "[!] Stamina: " << p1.getStamina() << "/" << p1.getMaxStamina() << endl;
            cout<< "[!] Current Goblin HP: " << g.getHealth() << "/" << g.getMaxHealth() << endl;
            cout<< " " << endl;
            }
            break;
        case 4:
            cout<< "[!] You decided to rest, you gained stamina!" << endl;
            p1.increaseStamina();
            if(p1.getStamina() > p1.getMaxStamina()){
                cout<< "[!] Oops! Max stamina is " << p1.getMaxStamina() << "." << endl;
                p1.setStamina();
             }
            cout<< "[!] The goblin attacked "<< p1.getName() << " and did " << p1.takeDmg(g.getDamage()) << " damage!"<< endl;
            if(death(p1, g)){
                return;
            }
            cout<< "[!] Player HP: " << p1.getHealth() <<  "/" << p1.getMaxHealth() << endl; 
            cout<< "[!] Stamina: " << p1.getStamina() << "/" << p1.getMaxStamina() << endl;
            cout<< "[!] Current Goblin HP: " << g.getHealth() << "/" << g.getMaxHealth() << endl;
            cout<< " " << endl;
            break;
        case 5:
            cout<< " " << endl;
            p1.shop();
            cout<< " " << endl;
            break;
        case 6:
            p1.displayStats();
            break;
        case 7:
            cout<< "-------------- Attack Log --------------"<< endl;
            cout<<"[!] You decided to run away like a little girl. Game over." << endl;
            gameRunning = false;
            break;
    }
}

// Checks if player or goblin has died
bool death(Player &p1, Goblin &g){
    // If goblin dies, move on to next level and give rewards
    if(g.getHealth() <= 0){
        int reward = ((rand() % 100) + 200 + (level*100));
        cout<<"[!] The goblin has died! Onto the next level!." << endl;
        cout<<"[+] "<< p1.addCoins(reward) << " coins!" << endl;
        cout<< " " << endl;
        level++;
        g.increaseDamage();
        g.resetHealth();
        // Increases goblin health every 2 levels
        if(level % 2 == 0){
         g.increaseHealth();
        }
        // Gives 500 coins every 5 levels
        if(level % 5 == 0){
            cout<< "[+] 350 Bonus coins for reaching level "<< level << "!" << endl;
            cout<< " " << endl;
            p1.addCoins(350);
        }
        return true;
    } else if(p1.getHealth() <= 0){
        // ends game
        cout<< "[!] "<< p1.getName() << " has died, Game over!" << endl;
        gameRunning = false;
        return true;
    }
    return false;
}
