#include <iostream>
#include "Array.h"

template<typename T>
Array returnDynamicArray(T arr[], const int size);

int main()
{
    srand((unsigned)time(NULL));
    const int size = 10;
    double arr[size];

    for (int i = 0; i < size; i++)
        arr[i] = -10 + rand() % int(10 - (-10) + 1);  //filled the array( -10 до 10)

    Array dynamicArray = returnDynamicArray(arr, size);

    dynamicArray.Print();

    Predicate<double>* zero = new Zero<double>(); //functor: "zero elements"
    Predicate<double>* positive = new Positive<double>(); //functor: "positive elements" 
    Predicate<double>* negative = new Negative<double>(); //functor: "negative elements" 
    Predicate<double>* even = new Even<double>(); //functor: "even elements" 
    Predicate<double>* odd = new Odd<double>(); //functor: "odd elements" 


    cout << "Number of elements(general): " << count(dynamicArray.begin(), dynamicArray.end()) << endl;

    cout << "Number of elements(zero): " << count_if(dynamicArray.begin(), dynamicArray.end(), *zero) << endl;
    cout << "Number of elements(positive): " << count_if(dynamicArray.begin(), dynamicArray.end(), *positive) << endl;
    cout << "Number of elements(negative): " << count_if(dynamicArray.begin(), dynamicArray.end(), *negative) << endl;
    cout << "Number of elements(even): " << count_if(dynamicArray.begin(), dynamicArray.end(), * even) << endl;
    cout << "Number of elements(odd): " << count_if(dynamicArray.begin(), dynamicArray.end(), *odd) << endl;

    

    return 0;
}
template<typename T>
Array returnDynamicArray(T arr[], const int size)
{
    Array dynamicArray = Array(size);

    for (int i = 0; i < size; i++)
        dynamicArray[i] = arr[i];

    return dynamicArray;
}