# Snake_game
Snake Game - C++
This project is a classic Snake game developed in C++ using Object-Oriented Programming (OOP) principles. The game includes basic features such as snake growth, eating fruits, colliding with itself, and tracking the score. The user can control the snake using arrow keys.

Technologies Used

-C++
-Object-Oriented Programming (OOP)
-Console Application

Project Features

-OOP is used to design separate classes for the snake, fruit, and game logic.
-The snake can move in four different directions (up, down, left, right).
-When the snake eats a fruit, it grows and the score increases.
-The game ends if the snake collides with itself.
-Fruits spawn at random locations and move every time they are eaten.
-The score is displayed during the game.

Project Classes

1. Object Class: An abstract class that ensures all objects have draw() and erase() methods.
2. Point1 (Snake): Represents each body part of the snake. It includes movement functions and coordinates management.
3. Point2 (Fruit): Represents the fruit’s position and includes a function to move it.
4. Fruit Class: Manages the functionality related to the fruit.
5. Snake Class: Manages the snake's movement, growth, collisions, and drawing on the screen.
6. Game Class: Controls the game loop, score tracking, and game over condition.

Game Rules

-The snake starts at a small size and moves to the right.
-The snake grows every time it eats a fruit.
-The game ends if the snake collides with itself.
-The user controls the snake with the W, A, S, D keys.
-The game starts with a score of 0, and 10 points are awarded for each fruit eaten.
