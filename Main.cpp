#include<iostream>
#include"Sudoku.h"
using namespace std;
int main(){
	Sudoku a;
	a.readAPuzzle();
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