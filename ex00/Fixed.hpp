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



class Fixed
{
    private:
        int32_t                 _value;
        static const int32_t    _fractionalBits;

    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& that);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);

};

#endif