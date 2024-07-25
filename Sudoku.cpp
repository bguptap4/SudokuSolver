// Sudoku.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define N 9
using namespace std;

bool isNumInRow(int grid[][N], int num, int row){
    for (int col = 0; col < N; col++) {
        if (grid[row][col] == num)
            return true;
    }
    return false;
}

bool isNumInCol(int grid[][N], int num, int col) {
    for (int row = 0; row < N; row++) {
        if (grid[row][col] == num)
            return true;
    }
    return false;
}

bool isNumIn3By3Grid(int grid[][N], int num, int startingRow, int startingCol) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[startingRow+i][startingCol+j] == num)
                return true;
        }
    }
    return false;
}

bool isNumFitAtPlace(int grid[][N], int num, int row, int col)
{
    return (!isNumInRow(grid, num, row) &&
    !isNumInCol(grid, num, col) &&
    !isNumIn3By3Grid(grid, num, row - row % 3, col - col % 3));
}

bool isAlreadySolved(int grid[][N], int& row, int& col) {
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == 0)
                return false;
    return true;
}

bool solve(int grid[][N]) {
    int row, col;
    if (isAlreadySolved(grid, row, col))
        return true;
    for (int num = 1; num <= 9; num++) {
        if (isNumFitAtPlace(grid, num, row, col)) {
            grid[row][col] = num;
            if (solve(grid))
                return true;
        }
        grid[row][col] = 0;
    }
    return false;
}

void printSudoku(int grid[N][N]) {
    cout << "Printing Sudoku" << endl;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cout << grid[r][c] << " ";
            if ((c + 1) % 3 == 0 && c < N - 1)  
                cout << "| "; 
        }
        cout << endl;
        if ((r + 1) % 3 == 0 && r < N - 1)
            cout << "------*-------*------" << endl;
    }
}

int main()
{
    int sudoku_grid1[N][N] = { {0,1,3,8,0,0,4,0,5},
        {0,2,4,6,0,5,0,0,0},
        {0,8,7,0,0,0,9,3,0},
        {4,9,0,3,0,6,0,0,0},
        {0,0,1,0,0,0,5,0,0},
        {0,0,0,7,0,1,0,9,3},
        {0,6,9,0,0,0,7,4,0},
        {0,0,0,2,0,7,6,8,0},
        {1,0,2,0,0,8,3,5,0} };

    int sudoku_grid2[N][N] = { {0,0,2,0,0,0,0,4,1},
        {0,0,0,0,8,2,0,7,0},
        {0,0,0,0,4,0,0,0,9},
        {2,0,0,0,7,9,3,0,0},
        {0,1,0,0,0,0,0,8,0},
        {0,0,6,8,1,0,0,0,4},
        {1,0,0,0,9,0,0,0,0},
        {0,6,0,4,3,0,0,0,0},
        {8,5,0,0,0,0,4,0,0} };

    printSudoku(sudoku_grid1);
    if (solve(sudoku_grid1)) {
        cout << endl << "********Solved Sudoku*************" << endl;
        printSudoku(sudoku_grid1);
    }
    else
        cout << "It seems that sudoku grid is not valid. Please check again"<<endl;
    cout << endl;
    printSudoku(sudoku_grid2);
    if (solve(sudoku_grid2)) {
        cout << endl<<"********Solved Sudoku*************" << endl;
        printSudoku(sudoku_grid2);
    }
    else
        cout << "It seems that sudoku grid is not valid. Please check again" << endl;

}