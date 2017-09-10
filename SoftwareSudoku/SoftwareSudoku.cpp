// SoftwareSudoku.cpp: 定义控制台应用程序的入口点。

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "FileUtil.h"


using namespace std;

void initData();
void switchNum();
void find(int index);

int n = 1000000;
int sudoku[9][9] = { 0 }, rows[10][10] = { 0 }, cloumns[10][10] = { 0 }, blocks[10][10] = { 0 }, num[81];

ofstream file;


int main()
{
	initData();
	find(0);
    return 0;
}

void initData() {
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++) {
			num[i * 9 + j] = i + 1;
		}
	}
	file.open("sudoku.txt");
	if (!file)
	{
		cout << "Open File　Error" << endl;
	}
}

void find(int index) {
	if (n <= 0){
		if (n == 0) {
			file.close();
			n--;
		}
		return;
	}
	int count = 0;
	if (index == 81) {
		switchNum();
		/**for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				file << sudoku[i][j] << " ";
			}
			file << endl;
			
		}
		if (n >= 2)
		{
			file << endl;
		}**/
		n--;
		return;
	}


	int t = num[index];
	for (int row = 0; row < 9; row++)//从第一行开始往下扫描
	{
		if (!rows[t][row]) {
			int b = row / 3;
			for (int block = b*3; block < b*3+3; block++)//每行会有3块九宫格可以扫描
			{
				if (!blocks[t][block])
				{
					int k = block % 3;
					for (int cloumn = k*3; cloumn < (k + 1) * 3; cloumn++)//每行每块会有3列可以扫描
					{
						if (!cloumns[t][cloumn]&&!sudoku[row][cloumn])
						{
							sudoku[row][cloumn] = t;
							blocks[t][block]  = 1;
							rows[t][row] = 1;
							cloumns[t][cloumn] = 1;
							find(index + 1);
							blocks[t][block] =0;
							rows[t][row] = 0;
							cloumns[t][cloumn] = 0;
							sudoku[row][cloumn] = 0;
						}
					}
				}
			}
			break;
		}
	}

}

int a = (4 + 4) % 9 + 1;

void switchNum() {
	int x = sudoku[0][0];
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (sudoku[i][j]==x)
			{
				sudoku[i][j] = a;
			}else if(sudoku[i][j]==a){
				sudoku[i][j] = x;
			}
		}
	}
}





