#include <iostream>
#include <assert.h>

#include <string>
#include <cfloat>
#include <cmath>
#include <sstream>

typedef union 
{
    float num;
    struct 
    {
        unsigned int mantissa: 23;
        unsigned int exponent: 8;
        unsigned int sign: 1;
    } raw;
} f754;

typedef union 
{
    double num;
    struct 
    {
        unsigned long mantissa: 52;
        unsigned int exponent: 11;
        unsigned int sign: 1;
    } raw;
} d754;

std::string binary_to_string(long n, int bits) 
{
    std::stringstream ss;
    for (int k = bits - 1; k >= 0; k--) {
        if ((n >> k) & 1)
            ss << '1';
        else
            ss << '0';
    }
    return ss.str();
}

std::string fp32_to_ieee754(float num)
{
    f754 n;
    n.num = num;
    std::stringstream ss;
    ss << n.raw.sign << " " << binary_to_string(n.raw.exponent, 8) 
        << ' ' << binary_to_string(n.raw.mantissa, 23);
    return ss.str();
}

std::string fp64_to_ieee754(double num)
{
    d754 n;
    n.num = num;
    std::stringstream ss;
    ss << n.raw.sign << " " << binary_to_string(n.raw.exponent, 11) 
        << ' ' << binary_to_string(n.raw.mantissa, 52);
    return ss.str();
}

void assert_ieee754_fp32(float num, std::string ieee754_f32)
{
    assert(ieee754_f32 == fp32_to_ieee754(num));
}

void assert_ieee754_fp64(double num, std::string ieee754_f64)
{
    assert(ieee754_f64 == fp64_to_ieee754(num));
}


void should_return_the_IEEE_754_of_float()
{
    assert_ieee754_fp32(+ 15.875f, "0 10000010 11111100000000000000000");
    assert_ieee754_fp32(- 1.0f,    "1 01111111 00000000000000000000000");
    assert_ieee754_fp32(2179992532741028265760653312.000000, "0 11011001 11000010110011111101100");
}

void should_return_the_IEEE_754_of_double()
{
    assert_ieee754_fp64(+ 15.875, "0 10000000010 1111110000000000000000000000000000000000000000000000");
    assert_ieee754_fp64(- 1.0,    "1 01111111111 0000000000000000000000000000000000000000000000000000");
}

void should_return_the_IEEE_754_of_float_edge()
{
    assert_ieee754_fp32(+ 0.0f,      "0 00000000 00000000000000000000000");
    assert_ieee754_fp32(- 0.0f,      "1 00000000 00000000000000000000000");
    assert_ieee754_fp32(+ HUGE_VALF, "0 11111111 00000000000000000000000");
    assert_ieee754_fp32(- HUGE_VALF, "1 11111111 00000000000000000000000");
    assert_ieee754_fp32(+ INFINITY,  "0 11111111 00000000000000000000000");
    assert_ieee754_fp32(- INFINITY,  "1 11111111 00000000000000000000000");
    assert_ieee754_fp32(+ NAN,       "0 11111111 10000000000000000000000");
    assert_ieee754_fp32(- NAN,       "1 11111111 10000000000000000000000");
    assert_ieee754_fp32(+ FLT_MAX,   "0 11111110 11111111111111111111111");
    assert_ieee754_fp32(- FLT_MAX,   "1 11111110 11111111111111111111111");
    assert_ieee754_fp32(+ FLT_MIN,   "0 00000001 00000000000000000000000");
    assert_ieee754_fp32(- FLT_MIN,   "1 00000001 00000000000000000000000");
}

void should_return_the_IEEE_754_of_double_edge()
{
    assert_ieee754_fp64(+ 0.0,      "0 00000000000 0000000000000000000000000000000000000000000000000000");
    assert_ieee754_fp64(- 0.0,      "1 00000000000 0000000000000000000000000000000000000000000000000000");
    assert_ieee754_fp64(+ HUGE_VAL, "0 11111111111 0000000000000000000000000000000000000000000000000000");
    assert_ieee754_fp64(- HUGE_VAL, "1 11111111111 0000000000000000000000000000000000000000000000000000");
    assert_ieee754_fp64(+ INFINITY, "0 11111111111 0000000000000000000000000000000000000000000000000000");
    assert_ieee754_fp64(- INFINITY, "1 11111111111 0000000000000000000000000000000000000000000000000000");
    assert_ieee754_fp64(+ NAN,      "0 11111111111 1000000000000000000000000000000000000000000000000000");
    assert_ieee754_fp64(- NAN,      "1 11111111111 1000000000000000000000000000000000000000000000000000");
    assert_ieee754_fp64(+ DBL_MAX,  "0 11111111110 1111111111111111111111111111111111111111111111111111");
    assert_ieee754_fp64(- DBL_MAX,  "1 11111111110 1111111111111111111111111111111111111111111111111111");
    assert_ieee754_fp64(+ DBL_MIN,  "0 00000000001 0000000000000000000000000000000000000000000000000000");
    assert_ieee754_fp64(- DBL_MIN,  "1 00000000001 0000000000000000000000000000000000000000000000000000");
}

int main()
{
    should_return_the_IEEE_754_of_float();
    should_return_the_IEEE_754_of_double();
    should_return_the_IEEE_754_of_float_edge();
    should_return_the_IEEE_754_of_double_edge();
    return 0;
}