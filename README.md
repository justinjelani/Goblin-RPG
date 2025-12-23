# GoblinRPG

GoblinRPG is a **turn-based, text-based RPG** built in C++ as part of my journey learning the language and practicing object-oriented programming.

This is my **first complete game project**. The initial version took about 30–60 minutes to implement, with additional time spent refining mechanics and balancing gameplay.

In the future, I plan to expand this project into a **full 2D game** and release it for free.

---

## Gameplay Overview

In GoblinRPG, you and a goblin take turns attacking each other.  
You can choose between **four different abilities** to help defeat your enemy.

- The game is turn-based
- Player input is handled via the **number keys**
- The player always has the first move

---

## Controls

- Use number keys ***(1–6)*** to select actions and abilities
- Follow on-screen prompts for combat choices

---

## Game Rules & Mechanics

- Fleeing from combat results in **instant death**.
- Using an ability **counts as a full turn**, this makes the game more strategic and challenging.
- The goblin attacks after the player’s turn.
- Upon death, the player can:
  - Quit the game
  - Respawn at **level 1** with all stats reset

---

## Technical Details

- Language: **C++**
- Style: Text-based terminal game
- Focus:
  - Object-oriented design
  - Turn-based logic
  - Game state management

---

## Future Plans

- Convert the game into a **2D application**
- Add improved UI and animations
- Expand abilities and enemy variety
- Improve overall game balance

---

## How to Run

1. Compile using `g++` or your preferred C++ compiler
2. Run the generated executable in a terminal

Example:
```bash
g++ *.cpp -o GoblinRPG
./GoblinRPG
