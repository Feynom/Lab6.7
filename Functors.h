#pragma once

template<class T> //interface describing functors - unary predicates
class Predicate
{
public:
	virtual bool operator () (T x) = 0;
};

template <class T>                  //implement the interface with a functor -                               
class Zero : public Predicate<T>    //check whether the value is zero
{
public:
	virtual bool operator () (T x)
	{
		T zero = T();
		return x == zero;
	}
};

template<class T>						// implement the interface with a functor -
class Positive : public Predicate<T>    //check whether the value is possitive
{
public:
	virtual bool operator () (T x)
	{
		return x > 0;
	}
};

template<class T>						// implement the interface with a functor -
class Negative : public Predicate<T>	//check whether the value is negative
{
public:
	virtual bool operator () (T x)
	{
		return x < 0;
	}
};

template<class T>					// implement the interface with a functor -
class Even : public Predicate<T>    //check whether the value is even
{
public:
	virtual bool operator () (T x)
	{
		return (int)x % 2 == 0;
	}
};

template<class T>					// implement the interface with a functor -
class Odd : public Predicate<T>    //check whether the value is odd
{
public:
	virtual bool operator () (T x)
	{
		return (int)x % 2 != 0;
	}
};

// myTask

template<class T>
int count(T* begin, T* end)
{
	int counter = 0;

	for (begin; begin < end; begin++)
		counter++;

	return counter;
}
template<class T>
int count_if(T* begin,T* end, Predicate<T>& predicate)
{
	int counter = 0;

	for (begin; begin < end; begin++)
		if (predicate(*begin))
			counter++;

	return counter;
}