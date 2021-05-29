#include "Sudoku.h"
#include<iostream>
using namespace std;
Sudoku::Sudoku() {
}
Sudoku::Sudoku(int newGrid[9][9]) {
    for (int i = 0;i < 9;i++) {
        for (int j = 0;j < 9;j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}
void Sudoku::readAPuzzle() {
    cout << "請輸入數獨:" << endl;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> grid[i][j];
}
void Sudoku::setPuzzle(int i,int j,int c) {
            grid[i][j]=c;
}
bool Sudoku::search() {
    int freeCellList[81][2]; //有81個格子並有2種座標(i,j)
    int numberOfFreeCells = getFreeCellList(grid, freeCellList);
    if (numberOfFreeCells == 0)
        return true; // 沒有更多空格了

    int k = 0; // 從第一個空格開始解
    while (true)
    {
        int i = freeCellList[k][0];
        int j = freeCellList[k][1];
        if (grid[i][j] == 0)
            grid[i][j] = 1; // 從1開始猜

        if (isValid(i, j))
        {
            if (k + 1 == numberOfFreeCells)
            { // 沒有更多空格了
                return true; // 找到了解
            }
            else
            { // 到下一個空格
                k++;
            }
        }
        else if (grid[i][j] < 9)
        {
            // 則往下找答案直到猜到數字9為止
            grid[i][j] = grid[i][j] + 1;
        }
        else
        { // 當猜到9的時候
            while (grid[i][j] == 9)
            {
                if (k == 0)
                {
                    return false; // 如果是第一格的話，則不可能有解
                }
                grid[i][j] = 0; // 該空格歸零
                k--; // 前往上一個空格
                i = freeCellList[k][0];
                j = freeCellList[k][1];
            }

            // 該空格數值繼續往下找
            grid[i][j] = grid[i][j] + 1;
        }
    }

    return true; //找到答案
}
int Sudoku::getFreeCellList(const int newGrid[9][9], int freeCellList[81][2]) {
    // 81格子是最大輸入了
    int numberOfFreeCells = 0;

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (grid[i][j] == 0)
            {
                freeCellList[numberOfFreeCells][0] = i;
                freeCellList[numberOfFreeCells][1] = j;
                numberOfFreeCells++;
            }

    return numberOfFreeCells;
}
void Sudoku::printGrid() {
    char a = 97;
    cout << "  A B C D E F G H I" << endl;//輸出邊框j軸
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++) {
            if (j == 0) {
                cout << a << " ";//輸出邊框i軸
                a++;
            }
            if (grid[i][j] != 0) {
                cout << grid[i][j] << " ";//如果有0的話則輸出空白
            }
            else
                cout << " ";

        }
        cout << endl;
    }
}
bool Sudoku::checkRow(int i, int j, int newGrid[9][9]) {
    for (int column = 0; column < 9; column++)
        if (column != j && newGrid[i][column] == newGrid[i][j])
            return false;
    return true;
}
bool Sudoku::checkCol(int i, int j, int newGrid[9][9]) {
    for (int row = 0; row < 9; row++)
        if (row != i && newGrid[row][j] == newGrid[i][j])
            return false;
    return true;
}
bool Sudoku::checkCube(int i, int j, int newGrid[9][9]) {
    for (int row = (i / 3) * 3; row < (i / 3) * 3 + 3; row++)
        for (int col = (j / 3) * 3; col < (j / 3) * 3 + 3; col++)
            if (row != i && col != j && newGrid[row][col] == newGrid[i][j])
                return false;
    return true;
}
bool Sudoku::isValid(int i, int j) {
    if (checkCol(i, j, grid) && checkRow(i, j, grid) && checkCube(i, j, grid))
        return true;
    else
        return false;
}
bool Sudoku::isValid() {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (grid[i][j] < 0 || grid[i][j] > 9 ||
                (grid[i][j] != 0 && !isValid(i, j)))
                return false;

    return true;
}