#pragma once
#include <iostream>

class Fixed
{
    private:
        int _num;
        static const int _frac = 8;

    public:
        Fixed();
        Fixed(const Fixed &src);
        Fixed &operator=(const Fixed &src);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
};
