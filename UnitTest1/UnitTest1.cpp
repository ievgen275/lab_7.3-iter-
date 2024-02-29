#include "pch.h"
#include "CppUnitTest.h"
#include "../PR_7.3(iter)/PR_7.3(iter).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestPart1_Count)
		{
			int rowCount = 3;
			int colCount = 3;
			int Low = -10;
			int High = 10;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			Create(a, rowCount, colCount, Low, High);
			int Sum = 0;
			bool result = Part1_Count(a, rowCount, colCount, Sum);

			Assert::IsTrue(result, L"There are negative elements, so the result should be true");
			Assert::AreNotEqual(0, Sum, L"The sum should not be zero");

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(NoSaddlePointInMatrix)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int** matrix = new int* [rowCount];
			for (int i = 0; i < rowCount; ++i)
			{
				matrix[i] = new int[colCount];
				for (int j = 0; j < colCount; ++j)
				{
					matrix[i][j] = (i + j) % 2 == 0 ? 1 : -1;
				}
			}

			for (int i = 0; i < rowCount; ++i)
			{
				delete[] matrix[i];
			}
			delete[] matrix;
		}
	};
}
