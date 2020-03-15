# SUDOKU APP
The objectives of the Sudoku App are:
- Create a sudoku game.
- Solve a sudoku game.
- Implement the solution using different languages.
- Create a GUI.

## Create a Sudoku Game

In order to solve a Sudoku, I need to have a Sudoku.

To create a Sudoko I implemented the following Functions:

- correctSudoku: returns 0 if the sudoku doesn't comply the rules. Repeated numbers by zone, column or row.
- createRow: constructs the row of a sudoku verifying available numbers.
- checkAvailableNumbers: returns a list of numbers available to play in the current position (row, column).
- pickAvailableNumber: returns a random number from the available numbers list from checkAvailableNumbers.
- resetSudoku: erases the sudoku. Use when the current attempt cannot yield a correct sudoku.

and some others.
