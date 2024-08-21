#pragma once

#include <iostream>

class Bureaucrat
{
    private:
        const std::string _name;

    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat &operator=(const Bureaucrat &src);
        ~Bureaucrat();
};