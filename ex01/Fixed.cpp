#include "Fixed.hpp"

const int32_t Fixed::_fractionalBits = 8;

Fixed::Fixed() : _value(0) 
{
    std::cout << GREEN << "Default constructor called.\n";
}

Fixed::Fixed(const int num) : _value(num << _fractionalBits) 
{
    std::cout <<  CYAN << "Int constructor called.\n";

}

Fixed::Fixed(const float fl) : _value(roundf(fl * (1 << _fractionalBits)))
{
    std::cout <<  CYAN << "Float constructor called.\n";

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

int Fixed::toInt(void) const
{
    return _value >> _fractionalBits;

}

float Fixed::toFloat(void) const
{
    return static_cast<float>(_value)/static_cast<float>(1 << _fractionalBits);
}

std::ostream& operator<<(std::ostream& os,const Fixed& that)
{
    os << that.toFloat();
    return os;
}