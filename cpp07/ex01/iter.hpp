#pragma once

#include <iostream>

template <typename T>
void iter(T *array, size_t len, void(*f)(T &))
{
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}

template <typename T>
void iter(T *array, size_t len, void(*f)(const T &))
{
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}

template<typename T>
void func(T &str)
{
	std::cout << str << std::endl;
}