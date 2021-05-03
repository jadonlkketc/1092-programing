//��row ��col 
#ifndef SUDOKU_H
#define SUDOKU_H
class Sudoku{
	public:
	Sudoku();//�p�Gԣ���S��J�N�q�{�կ�
	Sudoku(int number[10][10]);//��J��J�@�ǼƦr���ƿW
	bool checkCol(int,int, int newNumber[10][10]);//�ˬd���
	bool checkRow(int,int, int newNumber[10][10]);//�ˬd�ݦ�
	bool checkCube(int, int, int newNumber[10][10]);//�ˬd�Ѿl��4��
	bool checkAll(int,int,int newNumber[10][10]);//�H�W�T�ӳ��@�_�ˬd
	bool checkAllOfEach(int newNumber[10][10]);//�����ˬd
	void setNumber(int, int, int);//�ק�Number����
	void setMemory(int, int, int);//�ק�Memory����
	void setAnswer(int, int, int);//�ק�answer����
	void getSudoku();//�L�X�ƿW�D��
	void getAnswer();//�L�X�ƿW����
	void blankLocation(int a[52]);//���ťճB�]�߼���
	void possibleAnswer();//�ɤO�}�ѸӼƿW
private:
	int number[10][10];//�D��
	int answer[10][10];//���T����
	int memory[10][10];//�a�|�k�ΰ}�C
};
#endif
//�ŧi�ɿ�J�}�C


