// SoftwareSudoku.cpp: 定义控制台应用程序的入口点。

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "FileUtil.h"


using namespace std;

void initData();
void dfs(int index);

int n = 10000;
int res[9][9] = { 0 }, hang[10][10] = { 0 }, lie[10][10] = { 0 }, block[10][10] = { 0 };
int num[81];

ofstream file;


int main()
{
	initData();
	dfs(0);

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

void dfs(int index) {
	if (n <= 0){
		if (n == 0) {
			file.close();
			n--;
		}
		return;
	}
	int count = 0;
	
	if (index == 81) {
	
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
			
				file << res[i][j] << " ";
			}

			
		}
		if (n>=2)
		{
			file << endl;
		}
		
		n--;
		return;
	}


	int t = num[index];
	for (int width = 0; width < 9; width++)
	{
		if (!hang[t][width]) {
			int b = width / 3;
			for (int x = b*3; x < b*3+3; x++)
			{
				if (!block[t][x])
				{
					int k = x % 3;
					for (int y = k*3; y < (k + 1) * 3; y++)
					{
						if (!lie[t][y]&&!res[width][y])
						{
							block[t][x] = hang[t][width] = lie[t][y] = 1;
							res[width][y] = t;
							dfs(index + 1);
							block[t][x] = hang[t][width] = lie[t][y] = 0;
							res[width][y] = 0;
						}
					}
				}
				
			}
			break;
		}
	}

}





