#include "Sudoku.h"
#include<iostream>
using namespace std;
//初始原來的值為10X10的空格
Sudoku::Sudoku() {
	for (int i = 1;i < 10;i++) {
		for (int j = 1;j < 10;j++) {
			number[i][j] = {'\0'};
			answer[i][j] = {'\0'};
			memory[i][j] = { '\0' };
		}
	}
}
//把新的10X10空格覆蓋到原本的空格
Sudoku::Sudoku(int newNumber[10][10]) {
	for (int i = 1;i < 10;i++) {
		for (int j = 1;j < 10;j++) {
			number[i][j] = newNumber[i][j];
		}
	}
}
//檢查橫是否有衝突
bool Sudoku::checkCol(int i,int j,int newNumber[10][10]) {
	int n;
	n = newNumber[i][j];
	for (int m = 1;m < 10;m++) {
		if ((m != j) && (newNumber[i][m] == n) && (n != 0)) {
			return false;
			break;
		}
	}
	return true;
}
//檢查豎是否有衝突
bool Sudoku::checkRow(int i, int j, int newNumber[10][10]) {
	int n;
	n = newNumber[i][j];
	for (int m = 1;m < 10;m++) {
		if ((m != i) && (newNumber[m][j] == n)&&(n!=0)) {
			return false;
			break;
		}
	}
	return true;
}
//檢查3X3的範圍中剩下沒檢查到的4格
bool Sudoku::checkCube(int i, int j, int newNumber[10][10]) {
	int n, r, s;
	n = newNumber[i][j];
	r = (i - 1) / 3;
	s = (j - 1) / 3;
	for (int k = 1;k <=3;k++) {
		for (int l = 1;l <= 3;l++) {
			if ((3 * r + k != i) && (3 * s + l != j) && (newNumber[3 * r + k][3 * s + l] == n) && (n != 0)) {
				return false;
				break;
			}
		}
	}
	return true;
}
//將上述三個檢查統整一起
bool Sudoku::checkAll(int i, int j, int newNumber[10][10]) {
	if (checkCol(i, j,newNumber) && checkRow(i, j,newNumber) && checkCube(i, j,newNumber))
		return true;
	else 
		return false;
}
//每個格子都交叉比對
bool Sudoku::checkAllOfEach(int newNumber[10][10]) {
	for (int i = 1;i < 10;i++) {
		for (int j = 1;j < 10;j++) {
			if (checkAll(i, j, newNumber)) {

			}
			else {
				return false;
			}
		}
	}
	return true;
}
//設定第(i,j)格的n值
void Sudoku::setNumber(int i,int j,int n) {
	number[i][j] = n;
}
void Sudoku::setMemory(int i, int j, int n) {
	memory[i][j] = n;
}
void Sudoku::setAnswer(int i, int j, int n) {
	answer[i][j] = n;
}
//印出完整數獨題目畫面(未修飾)
void Sudoku::getSudoku() {
	for (int i = 1;i < 10;i++) {
		for (int j = 1;j < 10;j++) {
			cout << number[i][j]<<"  ";
		}
		cout << endl<<endl;
	}
}
//印出完整數獨答案畫面(未修飾)
void Sudoku::getAnswer() {
	for (int i = 1;i < 10;i++) {
		for (int j = 1;j < 10;j++) {
			cout << answer[i][j] << "  ";
		}
		cout << endl << endl;
	}
}
//在51空格處放入標記
void Sudoku::blankLocation(int a[52]) {
	for (int i = 1;i < 10;i++) {
		for (int j = 1;j < 10;j++) {
			for (int m = 1;m < 52;m++) {
				if (number[i][j] == '\0')
					setMemory(i, i, a[m]);
			}
		}
	}
}
//窮舉法，51格列舉
void Sudoku::possibleAnswer() {
	int a[52];
	for (int a1 = 1;a1 < 10;a1++) {
		a[1] = a1;
		for (int a2 = 1;a2 < 10;a2++) {
			a[2] = a2;
			for (int a3 = 1;a3 < 10;a3++) {
				a[3] = a3;
				for (int a4 = 1;a4 < 10;a4++) {
					a[4] = a4;
					for (int a5 = 1;a5 < 10;a5++) {
						a[5] = a5;
						for (int a6 = 1;a6 < 10;a6++) {
							a[6] = a6;
							for (int a7 = 1;a7 < 10;a7++) {
								a[7] = a7;
								for (int a8 = 1;a8 < 10;a8++) {
									a[8] = a8;
									for (int a9 = 1;a9 < 10;a9++) {
										a[9] = a9;
										for (int a10 = 1;a10 < 10;a10++) {
											a[10] = a10;
											for (int a11 = 1;a11 < 10;a11++) {
												a[11] = a11;
												for (int a12 = 1;a12 < 10;a12++) {
													a[12] = a12;
													for (int a13 = 1;a13 < 10;a13++) {
														a[13] = a13;
														for (int a14 = 1;a14 < 10;a14++) {
															a[14] = a14;
															for (int a15 = 1;a15 < 10;a15++) {
																a[15] = a15;
																for (int a16 = 1;a16 < 10;a16++) {
																	a[16] = a16;
																	for (int a17 = 1;a17 < 10;a17++) {
																		a[17] = a17;
																		for (int a18 = 1;a18 < 10;a18++) {
																			a[18] = a18;
																			for (int a19 = 1;a19 < 10;a19++) {
																				a[19] = a19;
																				for (int a20 = 1;a20 < 10;a20++) {
																					a[20] = a20;
																					for (int a21 = 1;a21 < 10;a21++) {
																						a[21] = a21;
																						for (int a22 = 1;a22 < 10;a22++) {
																							a[22] = a22;
																							for (int a23 = 1;a23 < 10;a23++) {
																								a[23] = a23;
																								for (int a24 = 1;a24 < 10;a24++) {
																									a[24] = a24;
																									for (int a25 = 1;a25 < 10;a25++) {
																										a[25] = a25;
																										for (int a26 = 1;a26 < 10;a26++) {
																											a[26] = a26;
																											for (int a27 = 1;a27 < 10;a27++) {
																												a[27] = a27;
																												for (int a28 = 1;a28 < 10;a28++) {
																													a[28] = a28;
																													for (int a29 = 1;a29 < 10;a29++) {
																														a[29] = a29;
																														for (int a30 = 1;a30 < 10;a30++) {
																															a[30] = a30;
																															for (int a31 = 1;a31 < 10;a31++) {
																																a[31] = a31;
																																for (int a32 = 1;a32 < 10;a32++) {
																																	a[32] = a32;
																																	for (int a33 = 1;a33 < 10;a33++) {
																																		a[33] = a33;
																																		for (int a34 = 1;a34 < 10;a34++) {
																																			a[34] = a34;
																																			for (int a35 = 1;a35 < 10;a35++) {
																																				a[35] = a35;
																																				for (int a36 = 1;a36 < 10;a36++) {
																																					a[36] = a36;
																																					for (int a37 = 1;a37 < 10;a37++) {
																																						a[37] = a37;
																																						for (int a38 = 1;a38 < 10;a38++) {
																																							a[38 ]= a38;
																																							for (int a39 = 1;a39 < 10;a39++) {
																																								a[39] = a39;
																																								for (int a40 = 1;a40 < 10;a40++) {
																																									a[40] = a40;
																																									for (int a41 = 1;a41 < 10;a41++) {
																																										a[41] = a41;
																																										for (int a42 = 1;a42 < 10;a42++) {
																																											a[42] = a42;
																																											for (int a43 = 1;a4 < 10;a43++) {
																																												a[43] = a43;
																																												for (int a44 = 1;a44 < 10;a44++) {
																																													a[44] = a44;
																																													for (int a45 = 1;a45 < 10;a45++) {
																																														a[45] = a45;
																																														for (int a46 = 1;a46 < 10;a46++) {
																																															a[46] = a46;
																																															for (int a47 = 1;a47 < 10;a47++) {
																																																a[47] = a47;
																																																for (int a48 = 1;a48 < 10;a48++) {
																																																	a[48] = a48;
																																																	for (int a49 = 1;a49 < 10;a49++) {
																																																		a[49] = a49;
																																																		for (int a50 = 1;a50 < 10;a50++) {
																																																			a[50] = a50;
																																																			for (int a51 = 1;a51 < 10;a51++) {
																																																				a[51] = a51;
																																																				blankLocation(a);
																																																				if (checkAllOfEach(memory)) {
																																																					for (int i = 1;i < 10;i++) {
																																																						for (int j = 1;j < 10;j++) {
																																																							setAnswer(i, j, memory[i][j]);
																																																						}
																																																					}
																																																					break;
																																																				}
																																																			}
																																																		}
																																																	}
																																																}
																																															}
																																														}
																																													}
																																												}
																																											}
																																										}
																																									}
																																								}
																																							}
																																						}
																																					}
																																				}
																																			}
																																		}
																																	}
																																}
																															}
																														}
																													}
																												}
																											}
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}