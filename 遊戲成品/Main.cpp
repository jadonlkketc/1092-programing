#include<iostream>
#include<iomanip>
#include <conio.h>
#include"Sudoku.h"
using namespace std;
int main() {
	Sudoku action;
	char location;
	//�Ĥ@��
	cout << "PC:�A�n�A�ڬOPC�A�ڷQ�M�z���@�ӹC���C" << endl
		<< "�ڳo�䦳�@�ӥկȡA�ЧA��J���N��l�ӥX�@�ӼƿW�D�ص��ڡC" << endl
		<< "�ӧڷ|�ɧکү઺�ѥX���סC" << endl << endl << endl
		<< "�կ�:" << endl;
		action.printGrid();
		cout << setw(20)<<" " << "PC:���UEnter�����~��";
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');//�U�@�B�A�ð���M�ŵe�������O
		system("cls");
		//�ĤG��
		cout << "PC:�ݨ�U�����@�i�կȤF��?" << endl
			<< "��ئ��^��r���A�z�i�H�z�L��J���覡���o�ӥկȦ������ܤ�" << endl
			<< "���L�бz��J�ŦX�ƿW�W�h" << endl
			<< "�W�h�p�U:(�b�U�@��)"<<endl;
		cout << "�կ�:"<<endl;
		action.printGrid();
		cout << setw(20) << " " << "PC:���UEnter�����~��";
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');//�U�@�B�A�ð���M�ŵe�������O
		system("cls");
		//�ĤT��
		cout << "PC:�ƿW�����k�D�`²��A�u���@���W�h�G" << endl
			<< "�C�@�C�B�C�@��M�C�ӤE�c�椺����" << endl
			<< "1��9���Ʀr�A�����i�H���ơC" << endl << endl
			<< "PC:���L�@���A�H�ϳo�ӳW�h�A�ڷ|�����A�@���A" << endl
			<< "�A�N�|�P�w�ѥ_�C"<<endl;
		cout << "�կ�:" << endl;
		action.printGrid();
		cout << setw(20) << " " << "PC:���UEnter�����~��";
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');//�U�@�B�A�ð���M�ŵe�������O
		system("cls");
		//�ĥ|��
		cout << "�կ�:" << endl;
		action.printGrid();
		cout << endl
			<< "PC:��J2�r��(��m)�M�Ʀr�ӭק�կȤW���T��" << endl
			<< "��A�קﵲ������UESC����Y�i�����A�ӧڷ|�}�l���D"<<endl;
		cout << setw(20) << " " << "PC:���UEnter�����~��";
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');//�U�@�B�A�ð���M�ŵe�������O
		system("cls");
		cout << "�D�د�:" << endl;
		action.printGrid();
		cout << "��J��ӭ^��(�j�g�P�p�g)�Ʀr�H�Τ@�ӼƦr�ӭק��D�ح�(�Y���ݭn�������Uesc)"<<endl;
		char a, b;
		int c;
		while (true)
		{
			if (_kbhit())
			{
				if (_getch() == 27) //�p�G���U�FESC�ثh���X�j��
				{
					system("cls");
					break;
				}
				else {
					cin >> a >> b >> c;
					if (a < b) {//���b�A�ϥΪ̥i���N���ǿ�J
						char swap;
						swap = a;
						a = b;
						b = swap;
					}
					if (a >= 97 && a <= 105 && b >= 65&&b<= 73&&c>=1&&c<=9) {//���b2 �p�G��J������ڪ��F��h�n�קK
						action.setPuzzle(a - 97, b - 65, c);
						system("cls");
						cout << "�D�د�:" << endl;
						action.printGrid();
						cout << "��J��ӭ^��(�j�g�P�p�g)�Ʀr�H�Τ@�ӼƦr�ӭק��D�ح�(�Y���ݭn�������Uesc)" << endl;
					}
					else {
						system("cls");
						cout << "�D�د�:" << endl;
						action.printGrid();
						cout << "��J�����T�A�A��J�@��" << endl;
						cout << "��J��ӭ^��(�j�g�P�p�g)�Ʀr�H�Τ@�ӼƦr�ӭק��D�ح�(�Y���ݭn�������Uesc)" << endl;
					}
					
				}
			}
		}
		system("cls");
	if (!action.isValid()) {
		cout << "�K!�������A�A�ÿ�J�@�q" << endl;
	}
	else if (action.search())
	{
		cout << "PC:�ѵ�:" << endl;
		action.printGrid();
	}
	else
		cout << "PC:�o���i��A�ک~�M��F�A���D�L�ѡC" << endl;

	return 0;
}