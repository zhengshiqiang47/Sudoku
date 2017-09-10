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
			// TODO: 在此输入测试代码
			initData();
			find(0);
		}

	};
}