#include "Harl.hpp"

int main (int argc, char **argv)
{
    if (argc != 2 || argv[1][0] == '\0')
    {
        std::cerr<<"Error: bad arguments"<<std::endl;
        return 1;
    }
    Harl harl;
    harl.complain(argv[1]);
    return 0;
}