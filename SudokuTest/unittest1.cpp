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
		TEST_METHOD(TestMethod1)
		{
			// TODO: �ڴ�������Դ���
			initData();
			find(0);
		}

	};
}