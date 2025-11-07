#ifndef FIXED_H
#define FIXED_H
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

# include <iostream>
# include <iomanip>
# include <cmath>



class Fixed
{
    private:
        int32_t                 _value;
        static const int32_t    _fractionalBits;

    public:
        Fixed();
        Fixed(const int num);
        Fixed(const float fl);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& that);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);

        int toInt(void) const;
        float toFloat(void) const;
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        bool operator<(const Fixed& other) const;
        bool operator>(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        Fixed& operator++();
        Fixed operator++(int); // dummy parameter -> postfix 
        Fixed& operator--();
        Fixed operator--(int);

        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static  const Fixed& max(const Fixed& a, const Fixed& b);       
};
std::ostream& operator<<(std::ostream& os,const Fixed& that);
    
#endif