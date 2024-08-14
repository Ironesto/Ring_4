#include "Fixed.hpp"

Fixed::Fixed()
{
	//std::cout<<"Default constructor called"<<std::endl;
	_num = 0;
}

Fixed::Fixed(const int num)
{
	//std::cout<<"Int constructor called"<<std::endl;
	this->_num = num << _frac;
}

Fixed::Fixed(const float num)
{
	//std::cout<<"Float constructor called"<<std::endl;
	this->_num = roundf(num * (1 << _frac));
}

Fixed::Fixed(const Fixed &src)
{
	//std::cout<<"Copy constructor called"<<std::endl;
   *this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	//std::cout<<"Copy assignment operator called"<<std::endl;
	this->_num = src.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	//std::cout<<"Destructor called"<<std::endl;
}

int Fixed::getRawBits( void ) const
{
	//std::cout<<"getRawBits member function called"<<std::endl;
	return _num;
}

void Fixed::setRawBits( int const raw )
{
	//std::cout<<"setRawBits member function called"<<std::endl;
	this->_num = raw;
}

float Fixed::toFloat( void ) const
{
	return(static_cast<float>(_num) / (1 << _frac));
}

int Fixed::toInt( void ) const
{
	return(_num >> _frac);
}

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}

bool Fixed::operator>(const Fixed &src) const
{
	return (this->toFloat() > src.toFloat());
}

bool Fixed::operator<(const Fixed &src) const
{
	return (this->toFloat() < src.toFloat());
}

bool Fixed::operator>=(const Fixed &src) const
{
	return (this->toFloat() >= src.toFloat());
}

bool Fixed::operator<=(const Fixed &src) const
{
	return (this->toFloat() <= src.toFloat());
}

bool Fixed::operator==(const Fixed &src) const
{
	return (this->toFloat() == src.toFloat());
}

bool Fixed::operator!=(const Fixed &src) const
{
	return (this->toFloat() != src.toFloat());
}

Fixed Fixed::operator+(const Fixed &src) const
{
	return Fixed(this->toFloat() + src.toFloat());
}

Fixed Fixed::operator-(const Fixed &src) const
{
	return Fixed(this->toFloat() - src.toFloat());
}

Fixed Fixed::operator*(const Fixed &src) const
{
	return Fixed(this->toFloat() * src.toFloat());
}

Fixed Fixed::operator/(const Fixed &src) const
{
	return Fixed(this->toFloat() / src.toFloat());
}

Fixed &Fixed::operator++()
{

	++this->_num;
    return *this;
	// this->_num = (this->toInt() + 1) << _frac;
	// return *this;
}

Fixed Fixed::operator++(int)
{

	// Fixed temp(*this);
    // temp._num = this->_num++;
    // return (temp);

	Fixed temp(*this);
	this->_num++;
	return temp;
}

Fixed &Fixed::operator--()
{

	++this->_num;
    return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_num++;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return b;
	else
		return a;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return b;
	else
		return a;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return b;
	else
		return a;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return b;
	else
		return a;
}
