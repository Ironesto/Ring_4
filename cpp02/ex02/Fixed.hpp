#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _num;
        static const int _frac = 8;

    public:
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed &src);
        Fixed &operator=(const Fixed &src);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;

        bool operator>(const Fixed &src) const;
        bool operator<(const Fixed &src) const;
        bool operator>=(const Fixed &src) const;
        bool operator<=(const Fixed &src) const;
        bool operator==(const Fixed &src) const;
        bool operator!=(const Fixed &src) const;
        Fixed &operator+(const Fixed &src);
        Fixed &operator-(const Fixed &src);
        Fixed &operator*(const Fixed &src);
        Fixed &operator/(const Fixed &src);
        Fixed &min(const Fixed &src);

};

std::ostream &operator<<(std::ostream &o, Fixed const &i);