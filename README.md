# Farkle

**Farkle** is a classic "push-your-luck" dice game implemented in **C++**, designed for the console or local execution. Inspired by the traditional rules of Farkle, it's built as a school project.

##  What Is Farkle?

Farkle is a fast-paced dice game where players roll six dice each turn, trying to score points through specific combinations (like 1s, 5s, three-of-a-kind, straights, etc.). Roll a non-scoring combination, and you “Farkle”—losing all the points accumulated that turn.

##  Project Overview

- **Language:** C++

##  Features (Potential / To Be Confirmed)

- **Dice Rolling Logic**: Simulates rolling six dice, scoring combinations, and enforcing Farkle rules.
- **Game Flow**: A turn-by-turn cycle that accepts input, calculates scores, and determines win conditions.
- **Scoring Mechanics**: Supports standard scoring rules (e.g., 1s, 5s, triples, straights) and handles turn-based decision logic.
- **Console Output**: Likely shows roll results, scoring decisions, and turn outcomes interactively.

##  Getting Started

Quick setup to run the game:

```bash
# Clone the repo
git clone https://github.com/wallace094/farkle.git
cd farkle

# Build (example commands—update based on your setup)
# For Visual Studio:
# - Open the .sln file and build inside Visual Studio IDE
# For g++:
g++ -std=c++17 *.cpp -o farkle

# Run it
./farkle
