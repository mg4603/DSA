// preprocessor directive that keep the header file from being included mutiple
// times 
#ifndef MATH_UTILS 
#define MATH_UTILS

// structures and classes are placed in the header file
struct Rectangle
{
    double length;
    double width;
};

// declare the namespace in the header file
namespace utilities
{
    // functions are declared in the header file
    double area(double length, double width);
    
    double area(double side);

    double area(Rectangle rectangle);
    
    // default arguments are only stated at declaration in the header file
    // they are not included in the implementation file
    double pow(double base, int exponent = 2);
}


#endif