#include<iostream>
#include"Sudoku.h"
using namespace std;
int main(){
	int grid[9][9];
	Sudoku a;
	a.readAPuzzle(grid);
	if (!a.isValid()) {
		cout << "���X�z����J" << endl;
	}
	else if (a.search())
	{
		cout << "�ѵ�:" << endl;
		a.printGrid();
	}
	else
		cout << "�L��:" << endl;

	return 0;
}