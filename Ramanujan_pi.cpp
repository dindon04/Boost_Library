#include <iostream>
#include <cmath>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>

using boost::multiprecision::cpp_dec_float_50;

template <typename T>

T Factorial_boost(int number)
{
    T factorial = 1;

    for (int i = 1; i <= number; ++i)
    {
        factorial *= i;
    }
    return factorial;
}

int main() 
{

    cpp_dec_float_50 sum = 0;

    for (int k = 0; k < 100; ++k) 
    {
        cpp_dec_float_50 numerator = Factorial_boost<cpp_dec_float_50>(4 * k) * (1103 + 26390 * k);
        
        cpp_dec_float_50 denominator = pow(Factorial_boost<cpp_dec_float_50>(k), 4) * pow(396, 4 * k);
       
        sum += numerator / denominator;
    }

    cpp_dec_float_50 result = (2 * std::sqrt(2) / 9801) * sum;

    result = 1 / result;

    std::cout << "Pi : " << result << std::endl;
    std::cout << "Pi (boost) : " << boost::math::constants::pi<cpp_dec_float_50>() << "\n";
}
