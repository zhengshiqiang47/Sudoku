#include "stdafx.h"
#include "fstream"


using namespace std;

int test2(int a,int b) {
	return a + b;
}

void saveFile(char* fileName, char* content) {
	ofstream file(fileName);
	file << content;
	file.close();
}

