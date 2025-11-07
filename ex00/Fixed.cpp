#include "Fixed.hpp"

const int32_t Fixed::_fractionalBits = 8;

Fixed::Fixed() : _value(0) 
{
    std::cout << GREEN << "Default constructor called.\n";
}

Fixed::Fixed(const Fixed& other) : _value(other._value)
{
    std::cout <<  YELLOW << "Copy constructor called.\n";
}

Fixed& Fixed::operator=(const Fixed& that)
{
    std::cout <<  YELLOW << "Copy assignment operator called.\n";
    _value = that._value;
    return *this;
}

Fixed::~Fixed() 
{
    std::cout << RED <<  "Destructor called.\n";
}

int Fixed::getRawBits(void) const
{
    std::cout << MAGENTA << "getRawBits member function called.\n";

    return this->_value;
}