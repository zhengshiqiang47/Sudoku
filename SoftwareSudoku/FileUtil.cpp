#include "stdafx.h"
#include "fstream"
#include "iostream"


using namespace std;


int test2(int a,int b) {
	return a + b;
}

void saveFile(char* fileName, char* content) {
	ofstream file(fileName);
	file << content;
	file.close();
}


void addFile(char* fileName, char* content) {
	ofstream file;
	file.open(fileName,ios::app);
	if (!file) //检查文件是否正常打开//不是用于检查文件是否存在
	{
		cout << "abc.txt can't open" << endl;
		abort(); //打开失败，结束程序
	}else {
		file << content;
		file.close();
	}
	
}


