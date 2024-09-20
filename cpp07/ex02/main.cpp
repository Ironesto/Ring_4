#include "Array.hpp"

// int main()
// {
// 	{
// 		try
// 		{
// 			std::cout << "\t--Test 1--" << std::endl;
// 			int n = 3;
// 			Array<std::string> str(n);
// 			str[0] = "hola";
// 			str[1] = "mundo";
// 			str[2] = "que tal";
// 			for (int i = 0; i <= n; i++)
// 				std::cout << "str[" << i << "]: " << str[i] << std::endl;
// 		}
// 		catch(const std::exception &e)
// 		{
// 			std::cout << e.what() << std::endl;
// 		}
// 	}
// 	{
// 		try
// 		{
// 			std::cout << "\t--Test 2--" << std::endl;
// 			int n = 4;
// 			Array<int> num(n);
// 			num[0] = 0;
// 			num[1] = 1;
// 			num[2] = 123;
// 			num[3] = 42;
// 			std::cout << "el tamaño es " << num.size() << std::endl;
// 			for (int i = 0; i <= n; i++)
// 				std::cout << "num[" << i << "]: " << num[i] << std::endl;
// 		}
// 		catch(const std::exception &e)
// 		{
// 			std::cout << e.what() << std::endl;
// 		}
// 	}
// 	return 0;
// }

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
		//std::cout << "mirror[" << i <<"] = " <<mirror[i] << ", numbers[" <<i<<"] = "<< numbers[i] << std::endl;
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}