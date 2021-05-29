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
    cout << "�п�J�ƿW:" << endl;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> grid[i][j];
}
void Sudoku::setPuzzle(int i,int j,int c) {
            grid[i][j]=c;
}
bool Sudoku::search() {
    int freeCellList[81][2]; //��81�Ӯ�l�æ�2�خy��(i,j)
    int numberOfFreeCells = getFreeCellList(grid, freeCellList);
    if (numberOfFreeCells == 0)
        return true; // �S����h�Ů�F

    int k = 0; // �q�Ĥ@�ӪŮ�}�l��
    while (true)
    {
        int i = freeCellList[k][0];
        int j = freeCellList[k][1];
        if (grid[i][j] == 0)
            grid[i][j] = 1; // �q1�}�l�q

        if (isValid(i, j))
        {
            if (k + 1 == numberOfFreeCells)
            { // �S����h�Ů�F
                return true; // ���F��
            }
            else
            { // ��U�@�ӪŮ�
                k++;
            }
        }
        else if (grid[i][j] < 9)
        {
            // �h���U�䵪�ת���q��Ʀr9����
            grid[i][j] = grid[i][j] + 1;
        }
        else
        { // ��q��9���ɭ�
            while (grid[i][j] == 9)
            {
                if (k == 0)
                {
                    return false; // �p�G�O�Ĥ@�檺�ܡA�h���i�঳��
                }
                grid[i][j] = 0; // �ӪŮ��k�s
                k--; // �e���W�@�ӪŮ�
                i = freeCellList[k][0];
                j = freeCellList[k][1];
            }

            // �ӪŮ�ƭ��~�򩹤U��
            grid[i][j] = grid[i][j] + 1;
        }
    }

    return true; //��쵪��
}
int Sudoku::getFreeCellList(const int newGrid[9][9], int freeCellList[81][2]) {
    // 81��l�O�̤j��J�F
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
    cout << "  A B C D E F G H I" << endl;//��X���j�b
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++) {
            if (j == 0) {
                cout << a << " ";//��X���i�b
                a++;
            }
            if (grid[i][j] != 0) {
                cout << grid[i][j] << " ";//�p�G��0���ܫh��X�ť�
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