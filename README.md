# 🐍 Snake Game in C++

![snake preview](https://github.com/cerenoezkan/Snake_game/blob/21c81073ed152cc52ad03c011539fe49f5b7f564/snake_game.png)

🎮 A classic Snake game built with C++ using OOP principles.
## Features

- Move snake with arrow keys
- Eat fruit to grow
- Score tracking
- Game over on self-collision

## Technologies

- C++
- Object-Oriented Programming (OOP)
- Console-based game


## Project Features

- 🧱 **OOP-based Structure**: Separate classes for the snake, fruit, and game logic.
- 🔼🔽◀️▶️ **4-Way Movement**: Snake can move in all directions.
- 🍎 **Fruit Eating**: Eating a fruit makes the snake grow and increases the score.
- 💥 **Collision Detection**: Game ends when the snake collides with itself.
- 🔀 **Random Fruit Spawn**: Fruits spawn at random locations and relocate after being eaten.
- 🧮 **Score Display**: Real-time score tracking during gameplay.

---

## Project Classes

1. **`Object` Class**  
  🔹 Abstract class to ensure all objects have `draw()` and `erase()` methods.

2. **`Point1` Class (Snake)**  
  🔹 Represents each body part of the snake. Handles movement and coordinates.

3. **`Point2` Class (Fruit)**  
  🔹 Manages fruit’s position and updates location when needed.

4. **`Fruit` Class**  
  🔹 Handles fruit-related logic like spawning and redrawing.

5. **`Snake` Class**  
  🔹 Controls movement, growth, collision logic, and drawing on screen.

6. **`Game` Class**  
  🔹 Manages the game loop, scoring, and game over conditions.

---

## Game Rules

- 🐍 Snake starts small and moves to the right.
- 🍎 Each fruit eaten adds to the snake’s length.
- ❌ Game ends if the snake hits itself.
- 🎮 Controls: `W`, `A`, `S`, `D` keys.
- 🧮 Score starts from 0 and increases by **+10** for every fruit eaten.

