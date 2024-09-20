#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>

template<typename T>
class Array
{
	private:
		T *_array;
		unsigned int _i;

	public:
		Array<T>() : _i(0) { _array = new T[0]; }
		Array<T>(unsigned int n) : _i(n) { _array = new T[n]; }
		Array<T>(const Array &src) { _array = NULL; *this = src; }
		Array &operator=(const Array &src)
		{
			if (this != &src)
			{
				delete []_array;
				this->_i = src._i;
				this->_array = new T[this->_i];
				for (unsigned int j = 0; j < this->_i; j++)
					this->_array[j] = src._array[j];
			}
			return *this;
		}
		~Array<T>() 
		{
			if (_array != NULL)
				delete []_array;
		}

		T &operator[](unsigned int n) const 
		{
			if (n >= this->_i || _array == NULL)
				throw (ArrayException());
			return this->_array[n];
		}

		class ArrayException : public std::exception
		{
			public:
				virtual const char* what() const throw() { return ("Error: out of bounds"); }
		};

		unsigned int size() const { return this->_i; }
};