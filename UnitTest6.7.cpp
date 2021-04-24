#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6.7/Array.h"
#include "../Lab6.7/Array.cpp"
#include "../Lab6.7/Functors.h"
#include "../Lab6.7/Lab6.7.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest67
{
	TEST_CLASS(UnitTest67)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int arr[] = { 0, 5, -4, 5, -5, -4, 8, -9 ,0 ,20};
			Array dynamicArray = returnDynamicArray(arr, 10);

			Predicate<double>* zero = new Zero<double>(); //functor: "zero elements"
			Predicate<double>* positive = new Positive<double>(); //functor: "positive elements" 
			Predicate<double>* negative = new Negative<double>(); //functor: "negative elements" 
			Predicate<double>* even = new Even<double>(); //functor: "even elements" 
			Predicate<double>* odd = new Odd<double>(); //functor: "odd elements" 

			Assert::AreEqual(count(dynamicArray.begin(), dynamicArray.end()), 10); // all the elements
			Assert::AreEqual(count_if(dynamicArray.begin(), dynamicArray.end(), *zero), 2); //zero elements
			Assert::AreEqual(count_if(dynamicArray.begin(), dynamicArray.end(), *positive), 4);//positive elements
			Assert::AreEqual(count_if(dynamicArray.begin(), dynamicArray.end(), *negative), 4);//negative elements
			Assert::AreEqual(count_if(dynamicArray.begin(), dynamicArray.end(), *even), 6);//even element
			Assert::AreEqual(count_if(dynamicArray.begin(), dynamicArray.end(), *odd), 4);//odd element
			
		}
	};
}
