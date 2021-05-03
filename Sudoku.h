//豎row 橫col 
#ifndef SUDOKU_H
#define SUDOKU_H
class Sudoku{
	public:
	Sudoku();//如果啥都沒輸入就默認白紙
	Sudoku(int number[10][10]);//輸入填入一些數字的數獨
	bool checkCol(int,int, int newNumber[10][10]);//檢查橫行
	bool checkRow(int,int, int newNumber[10][10]);//檢查豎行
	bool checkCube(int, int, int newNumber[10][10]);//檢查剩餘的4格
	bool checkAll(int,int,int newNumber[10][10]);//以上三個都一起檢查
	bool checkAllOfEach(int newNumber[10][10]);//全面檢查
	void setNumber(int, int, int);//修改Number的值
	void setMemory(int, int, int);//修改Memory的值
	void setAnswer(int, int, int);//修改answer的值
	void getSudoku();//印出數獨題目
	void getAnswer();//印出數獨答案
	void blankLocation(int a[52]);//幫空白處設立標籤
	void possibleAnswer();//暴力破解該數獨
private:
	int number[10][10];//題目
	int answer[10][10];//正確答案
	int memory[10][10];//窮舉法用陣列
};
#endif
//宣告時輸入陣列


