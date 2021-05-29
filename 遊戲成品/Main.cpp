#include<iostream>
#include<iomanip>
#include <conio.h>
#include"Sudoku.h"
using namespace std;
int main() {
	Sudoku action;
	char location;
	//第一頁
	cout << "PC:你好，我是PC，我想和您玩一個遊戲。" << endl
		<< "我這邊有一個白紙，請你填入任意格子來出一個數獨題目給我。" << endl
		<< "而我會盡我所能的解出答案。" << endl << endl << endl
		<< "白紙:" << endl;
		action.printGrid();
		cout << setw(20)<<" " << "PC:按下Enter按鍵繼續";
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');//下一步，並執行清空畫面的指令
		system("cls");
		//第二頁
		cout << "PC:看到下面那一張白紙了嗎?" << endl
			<< "邊框有英文字母，您可以透過輸入的方式讓這個白紙有任何變化" << endl
			<< "不過請您輸入符合數獨規則" << endl
			<< "規則如下:(在下一頁)"<<endl;
		cout << "白紙:"<<endl;
		action.printGrid();
		cout << setw(20) << " " << "PC:按下Enter按鍵繼續";
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');//下一步，並執行清空畫面的指令
		system("cls");
		//第三頁
		cout << "PC:數獨的玩法非常簡單，只有一條規則：" << endl
			<< "每一列、每一行和每個九宮格內均有" << endl
			<< "1至9的數字，但不可以重複。" << endl << endl
			<< "PC:不過一旦你違反這個規則，我會視為你作弊，" << endl
			<< "你就會判定敗北。"<<endl;
		cout << "白紙:" << endl;
		action.printGrid();
		cout << setw(20) << " " << "PC:按下Enter按鍵繼續";
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');//下一步，並執行清空畫面的指令
		system("cls");
		//第四頁
		cout << "白紙:" << endl;
		action.printGrid();
		cout << endl
			<< "PC:輸入2字母(位置)和數字來修改白紙上的訊息" << endl
			<< "當你修改結束後按下ESC按鍵即可結束，而我會開始解題"<<endl;
		cout << setw(20) << " " << "PC:按下Enter按鍵繼續";
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');//下一步，並執行清空畫面的指令
		system("cls");
		cout << "題目紙:" << endl;
		action.printGrid();
		cout << "輸入兩個英文(大寫與小寫)數字以及一個數字來修改題目值(若不需要直接按下esc)"<<endl;
		char a, b;
		int c;
		while (true)
		{
			if (_kbhit())
			{
				if (_getch() == 27) //如果按下了ESC建則跳出迴圈
				{
					system("cls");
					break;
				}
				else {
					cin >> a >> b >> c;
					if (a < b) {//防呆，使用者可任意順序輸入
						char swap;
						swap = a;
						a = b;
						b = swap;
					}
					if (a >= 97 && a <= 105 && b >= 65&&b<= 73&&c>=1&&c<=9) {//防呆2 如果輸入不切實際的東西則要避免
						action.setPuzzle(a - 97, b - 65, c);
						system("cls");
						cout << "題目紙:" << endl;
						action.printGrid();
						cout << "輸入兩個英文(大寫與小寫)數字以及一個數字來修改題目值(若不需要直接按下esc)" << endl;
					}
					else {
						system("cls");
						cout << "題目紙:" << endl;
						action.printGrid();
						cout << "輸入不正確，再輸入一次" << endl;
						cout << "輸入兩個英文(大寫與小寫)數字以及一個數字來修改題目值(若不需要直接按下esc)" << endl;
					}
					
				}
			}
		}
		system("cls");
	if (!action.isValid()) {
		cout << "嘿!不公平，你亂輸入一通" << endl;
	}
	else if (action.search())
	{
		cout << "PC:解答:" << endl;
		action.printGrid();
	}
	else
		cout << "PC:這不可能，我居然輸了，此題無解。" << endl;

	return 0;
}