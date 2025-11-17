# 🎮 Tic-Tac-Toe Game Assignment (C++)

## 🎯 Objective

Write a C++ program that allows **two players** to play the
**Tic-Tac-Toe** game using a **class-based design**.

------------------------------------------------------------------------

## 🧩 Program Requirements

### 1. Class Name

`TicTacToe` --- The class must represent the entire game.

### 2. Private Members

-   A 3×3 2D array `board[3][3]` to store the moves (`'X'`, `'O'`, or
    `' '`).
-   Additional variables as needed (e.g., current player, move count,
    game status).

### 3. Public Member Functions

-   `void displayBoard()` → Print the current game board.\
-   `bool isValidMove(int row, int col)` → Check if a move is valid.\
-   `void makeMove(int row, int col)` → Place the move on the board.\
-   `bool checkWinner()` → Determine if there's a winner.\
-   `bool isDraw()` → Check for draw condition.\
-   `void playGame()` → Run the full game loop.

### 4. Gameplay Rules

-   Player 1 uses `'X'`, Player 2 uses `'O'`.
-   Players take turns entering row and column numbers (1--3).
-   After each move, the board updates and the winner/draw is checked.

### 5. Submission

-   Push your `.cpp` file to **GitHub**.
-   Submit your **GitHub repository link** on **Canvas**.

### 6. Code Requirements

-   Include **clear comments** for each function and logic step.
-   Follow **proper indentation** and **naming conventions**.

------------------------------------------------------------------------

## 🧱 UML Diagram

``` plaintext
+----------------------+
|      TicTacToe       |
+----------------------+
| - board[3][3]: char  |
| - currentPlayer: char|
| - moveCount: int     |
+----------------------+
| + TicTacToe()        |
| + displayBoard(): void|
| + isValidMove(r,c): bool|
| + makeMove(r,c): void |
| + checkWinner(): bool |
| + isDraw(): bool      |
| + switchPlayer(): void|
| + playGame(): void    |
+----------------------+
```

------------------------------------------------------------------------

## 🧠 Rubric (Total: 100 points)

| Criteria                  | Description                                                  | Points |
| ------------------------- | ------------------------------------------------------------ | :----: |
| Class Design (Structure)  | Well-defined `TicTacToe` class with private data and public methods. |   15   |
| Board Implementation      | Uses a 3×3 2D array to represent and display the board correctly. |   10   |
| Game Logic                | Validates moves, switches turns, and runs full gameplay flow. |   20   |
| Winner & Draw Detection   | Correctly detects win and draw conditions after each move.   |   15   |
| User Interaction          | Clear prompts; board displayed after each move; inputs handled gracefully. |   10   |
| Comments & Readability    | Meaningful comments, consistent indentation, descriptive names. |   10   |
| OOP Principles            | Encapsulation; minimal globals; class-based structure is appropriate. |   10   |
| GitHub Submission         | Code pushed to GitHub; working repository link shared on Canvas. |   5    |
| Program Execution         | Compiles and runs without syntax or runtime errors.          |   5    |
| Extra Features (Optional) | Replay option, colored output, or simple AI player.          |  +5*   |

**Total Points:** 100 (*Bonus up to +5)
