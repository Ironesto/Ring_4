#include <iostream>
//#include <ctype.h>

int main(int argc, char **argv)
{
    int i;
    int k = 1;

    if (argc < 2)
    {
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        return (0);
    }
    std::string str=argv[1];
    while (argv[k])
    {
        i = 0;
        str = argv[k];
        while (str[i] && str[i] != '\0')
        {
            str[i] = toupper(str[i]);
            std::cout<<str[i];
            i++;
        }
        k++;
    }
    return (0);
}