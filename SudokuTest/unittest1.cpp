#include "stdafx.h"
#include "CppUnitTest.h"
#include "iostream"
#include "fstream"
#include "../SoftwareSudoku/SoftwareSudoku.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SudokuTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		int n = 1000000;
		int a = (4 + 4) % 9 + 1;
		int sudoku[9][9] = { 0 }, rows[10][10] = { 0 }, cloumns[10][10] = { 0 }, blocks[10][10] = { 0 }, num[81];

		ofstream file;
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
				cout << "Open File��Error" << endl;
			}
		}

		void switchNum() {
			int x = sudoku[0][0];
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (sudoku[i][j] == x)
					{
						sudoku[i][j] = a;
					}
					else if (sudoku[i][j] == a) {
						sudoku[i][j] = x;
					}
				}
			}
		}
		
		void find(int index) {
			if (n <= 0) {
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
			for (int row = 0; row < 9; row++)//�ӵ�һ�п�ʼ����ɨ��
			{
				if (!rows[t][row]) {
					int b = row / 3;
					for (int block = b * 3; block < b * 3 + 3; block++)//ÿ�л���3��Ź������ɨ��
					{
						if (!blocks[t][block])
						{
							int k = block % 3;
							for (int cloumn = k * 3; cloumn < (k + 1) * 3; cloumn++)//ÿ��ÿ�����3�п���ɨ��
							{
								if (!cloumns[t][cloumn] && !sudoku[row][cloumn])
								{
									sudoku[row][cloumn] = t;
									blocks[t][block] = 1;
									rows[t][row] = 1;
									cloumns[t][cloumn] = 1;
									find(index + 1);
									blocks[t][block] = 0;
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

		TEST_METHOD(TestMethod1)
		{
			// TODO: �ڴ�������Դ���
			initData();
			find(0);
		}

	};
}