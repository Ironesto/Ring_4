#pragma once

#include <iostream>

class Bureaucrat
{
    private:
        const   std::string _name;
        int     _grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat &operator=(const Bureaucrat &src);
        ~Bureaucrat();

        std::string getName() const;
        //void setName(std::string name);
        int getGrade() const;
        //void setGrade(int grade);

        void GradeTooHighException(int grade);
        void GradeTooLowException(int grade);
};

std::ofstream &operator<<(std::ofstream &o, const Bureaucrat &src);