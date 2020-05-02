#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Task1Cpp/IndexerCPP.h"
#include "../Task1Cpp/IndexerCPP.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IndexerTestCPP
{
	TEST_CLASS(UnitTest1)
	{
	public:

		double* array = new double[] { 1, 2, 3, 4 };

		TEST_METHOD (HaveCorrectLength)
		{
			IndexerCPP indexer = IndexerCPP(array, 4, 1, 2);
			Assert::AreEqual(2, indexer.Length());
		}
		TEST_METHOD (GetCorrectly)
		{
			IndexerCPP indexer = IndexerCPP(array, 4, 1, 2);
			Assert::AreEqual((double)2, indexer[0]);
			Assert::AreEqual((double)3, indexer[1]);
		}
		TEST_METHOD (SetCorrectly)
		{
			IndexerCPP indexer = IndexerCPP(array, 4, 1, 2);
			indexer[0] = 10;
			Assert::AreEqual((double)10, array[1]);
		}
		TEST_METHOD (IndexerDoesNotCopyArray)
		{
			IndexerCPP indexer1 = IndexerCPP(array, 4, 1, 2);
			IndexerCPP indexer2 = IndexerCPP(array, 4, 0, 2);
			indexer1[0] = 100500;
			Assert::AreEqual((double)100500, indexer2[1]);
		}
		TEST_METHOD (FailWithWrongArguments1)
		{
			Assert::ExpectException<std::invalid_argument>([&] { IndexerCPP(array, 4, -1, 3); });
		}
		TEST_METHOD(FailWithWrongArguments2)
		{
			Assert::ExpectException<std::invalid_argument>([&] { IndexerCPP(array, 4, 1, -1); });

		}
		TEST_METHOD(FailWithWrongArguments3)
		{
			Assert::ExpectException<std::invalid_argument>([&] { IndexerCPP(array, 4, 1, 10); });
		}
		TEST_METHOD(FailWithWrongIndexing1)
		{
			auto indexer = IndexerCPP(array, 4, 1, 2);
			Assert::ExpectException<std::out_of_range>([&] { indexer[-1]; });
		}
		TEST_METHOD(FailWithWrongIndexing2)
		{
			auto indexer = IndexerCPP(array, 4, 1, 2);
			Assert::ExpectException<std::out_of_range>([&] { indexer[10]; });
		}
	};
}