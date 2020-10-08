#include "pch.h"
#include "CppUnitTest.h"
#include "\GIT\Anytype_Task_2\Anytype.h"
#include "\GIT\Anytype_Task_2\Anytype.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AnytypeUnitTests
{
	TEST_CLASS(AnytypeTests)
	{
	public:

		BEGIN_TEST_METHOD_ATTRIBUTE(ToIntTest)
			TEST_PRIORITY(1)
			END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(ToIntTest)
		{
			Anytype callObj1(10);
			int ret = callObj1.ToInt();
			Assert::AreEqual(ret, 10, L"Result should be 10");
			Assert::AreNotEqual(ret, 12, L"Result should be 10");
		}




		BEGIN_TEST_METHOD_ATTRIBUTE(ToDoubleTest)
			TEST_PRIORITY(2)
		    END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(ToDoubleTest)
		{
			Anytype callObj1(10.10);
			double ret  = callObj1.ToDouble();
			Assert::AreEqual(ret, 10.10, L"Result should be 10.10");
			Assert::AreNotEqual(ret, 10.12, L"Result should be 10.10");
		}




		BEGIN_TEST_METHOD_ATTRIBUTE(ToCharTest)
			TEST_PRIORITY(3)
			END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(ToCharTest)
		{
			Anytype callObj1('A');
			char ret = callObj1.ToChar();
			Assert::AreEqual(ret, 'A', L"Result should be 'A'");
			Assert::AreNotEqual(ret, 'B', L"Result should be 'A'");
		}




		BEGIN_TEST_METHOD_ATTRIBUTE(ToBoolTest)
			TEST_PRIORITY(4)
			END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(ToBoolTest)
		{
			Anytype callObj1(false);
			bool ret = callObj1.ToBool();
			Assert::AreEqual(ret, false, L"Result should be False");
			Assert::AreNotEqual(ret, true, L"Result should be False");
		}




		BEGIN_TEST_METHOD_ATTRIBUTE(swapTest)
			TEST_PRIORITY(5)
			END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(swapTest)
		{
			Anytype obj1('A');
			Anytype obj2(10);
			obj1.swap(obj2);
			Assert::AreEqual(obj1.ToInt(), 10, L"result should be 10");
			Assert::AreEqual(obj2.ToChar(), 'A', L"result should be 'A'");
		}




		BEGIN_TEST_METHOD_ATTRIBUTE(constr_copy_Test)
			TEST_PRIORITY(6)
			END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(constr_copy_Test)
		{
			Anytype obj1('A');
			Anytype obj2(obj1);
			Assert::AreEqual(obj2.ToChar(), 'A', L"result should be 'A'");
			Assert::AreNotEqual(obj2.ToChar(), 'B', L"result should be 'A'");
		}




		BEGIN_TEST_METHOD_ATTRIBUTE(OperatorTest)
			TEST_PRIORITY(7)
			END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(OperatorTest)
		{
			Anytype obj1('A');
			double tmp = 100.12;
			obj1 = tmp;
			Assert::AreEqual(obj1.ToDouble(), 100.12, L"result should be 100.12");
		}





	};
}
 