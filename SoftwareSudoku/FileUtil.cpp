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
	if (!file) //����ļ��Ƿ�������//�������ڼ���ļ��Ƿ����
	{
		cout << "abc.txt can't open" << endl;
		abort(); //��ʧ�ܣ���������
	}else {
		file << content;
		file.close();
	}
	
}


