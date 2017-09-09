// SoftwareSudoku.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "fstream"

using namespace std;

void saveFile(char* fileName, char* content);

int main()
{
	saveFile("sudoku.txt", "HelloWorld");
    return 0;
}

void saveFile(char* fileName,char* content) {
	ofstream file(fileName);
	file << content;
	file.close();
}

