#include "Fixed.hpp"

const int32_t Fixed::_fractionalBits = 8;

Fixed::Fixed() : _value(0) 
{
    std::cout << GREEN << "Default constructor called.\n";
    std::cout << RESET;
}

Fixed::Fixed(const int num) : _value(num << _fractionalBits) 
{
    std::cout <<  CYAN << "Int constructor called.\n";
    std::cout << RESET;
}

Fixed::Fixed(const float fl) : _value(roundf(fl * (1 << _fractionalBits)))
{
    std::cout <<  CYAN << "Float constructor called.\n";
    std::cout << RESET;
}

Fixed::Fixed(const Fixed& other) : _value(other._value)
{
    std::cout <<  YELLOW << "Copy constructor called.\n";
    std::cout << RESET;

}

Fixed& Fixed::operator=(const Fixed& that)
{
    std::cout <<  YELLOW << "Copy assignment operator called.\n";
    std::cout << RESET;
    _value = that._value;
    return *this;
}

Fixed::~Fixed() 
{
    std::cout << RED <<  "Destructor called.\n";
    std::cout << RESET;

}

int Fixed::getRawBits(void) const
{
    std::cout << MAGENTA << "getRawBits member function called.\n";
    std::cout << RESET;
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

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->getRawBits() + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->getRawBits() - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    result.setRawBits((this->_value * other._value) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;
    result.setRawBits((this->_value << _fractionalBits)/ other._value);
    return result;
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->_value < other._value;
}

bool Fixed::operator>(const Fixed& other) const
{
    return this->_value > other._value;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->_value <= other._value;
}


bool Fixed::operator>=(const Fixed& other) const
{
    return this->_value >= other._value;
}


bool Fixed::operator==(const Fixed& other) const
{
    return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->_value != other._value;
}


Fixed& Fixed::operator++()
{
    _value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    //preserve the original state
    Fixed temp(*this);
    _value++;
    return temp;
}

Fixed& Fixed::operator--()
{
    _value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    //preserve the original state
    Fixed temp(*this);
    _value--;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return a;
    else
        return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return a;
    else
        return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return a;
    else
        return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return a;
    else
        return b;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}