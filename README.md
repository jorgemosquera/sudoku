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

The application creates a valid sudoku.

<p align="center">
<img src="/images/sudoku.png" width="300">
</p>

### Difficulty Level

Now is time to erase numbers to the sudoku according to the difficulty level the user wants to play.

Currently I have to approaches:
1. Define difficulty according to the quantity of numbers erase.
2. Define difficulty according to the steps taken by an agent to solve the sudoku.

As I don't have the agent yet, I will implement the first one.  

Update:03-23-2020 After some reading and testing, just erasing numbers from a sudoku can cause an unsolvable sudoku. Therefore it is necessary to implement the agent first.

### Agent

1. solveByOnePositionInZone: this is the first method to solve a sudoku.
Basically in a 3x3 block you look the available places to put a missing number. If the number can only by in one position then we can place the number there.
After testing, this function can solve easy level sudokus.

<p align="center">
<img src="/images/easySudoku.png" width="300">
</p>

2. solveByRow, solveByColumn: another easy method to place numbers is to look for missing numbers in a row or a column. Again if a missing number can only by in one position, we put the number there.
These two functions extend the number of easy sudokus we can solve with the agent.
