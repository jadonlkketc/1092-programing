#ifndef SUDOKU_H
#define SUDOKU_H
class Sudoku{
	public:
		Sudoku();
		Sudoku(int newGrid[9][9]);
		void readAPuzzle(int newGrid[9][9]);
		bool search();
		int getFreeCellList(const int newGrid[9][9], int newFreeCellList[81][2]);
		void printGrid();
		bool checkRow(int, int, int newGrid[9][9]);
		bool checkCol(int, int, int newGrid[9][9]);
		bool checkCube(int, int, int newGrid[9][9]);
		bool isValid(int,int);
		bool isValid();
private:
	int grid[9][9]{};
};
#endif


