#include <iostream>

class Brain
{
    private:
        std::string _ideas[100];

    public:
        Brain();
        Brain(const Brain &src);
        Brain &operator=(const Brain &src);
        ~Brain();
};