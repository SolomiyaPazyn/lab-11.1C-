#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 11.1 C++.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// Тест: файл без послідовностей ",-"
			const char* testFile = "test1.txt";
			std::ofstream fout(testFile);
			fout << "This is a test file.\nAnother line without target.\n";
			fout.close();

			int count = SearchInFile(testFile);
			Assert::AreEqual(0, count);

			std::remove(testFile); // Видаляємо тестовий фай
		}
	};
}
