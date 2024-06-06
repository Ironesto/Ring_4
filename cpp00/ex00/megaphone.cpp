#include <iostream>
//#include <ctype.h>

int main(int argc, char **argv)
{
    std::string str=argv[1];
    char c = toupper('c');
    str[1] = toupper(str[1]);
    //std::toupper(str[1]);
    std::cout<<c;
    std::cout<<"hola mundo "<<str<<std::endl;
    return (0);
}