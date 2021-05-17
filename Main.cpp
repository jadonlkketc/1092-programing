#include<iostream>
#include"Sudoku.h"
using namespace std;
int main(){
	Sudoku a;
	a.readAPuzzle();
	if (!a.isValid()) {
		cout << "不合理的輸入" << endl;
	}
	else if (a.search())
	{
		cout << "解答:" << endl;
		a.printGrid();
	}
	else
		cout << "無解" << endl;

	return 0;
}
