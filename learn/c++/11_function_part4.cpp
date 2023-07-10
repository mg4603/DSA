#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// function declaration and defintion
// parameter names and argument names don't have to be the same
double power(double base, int exponent)
{
    double result(1);
    for(int i(0); i < exponent ; i++)
    {
        result *= base;
    }
    return result;
}

// function declaration - needs to be before function use
int read_int(std::string);

int main()
{
    cout << "In function part4" << endl;
    int base = read_int("What is the base?");
    int exponent = read_int("What is the exponent?");
    double my_power = power(base, exponent);

    // when a function returns a value, the returned value can be:
    //      * stored in a variable
    //      * output to some ostream object
    //      * used in some expression
    //      * passed as argument to some other function call
    cout << my_power << endl;
    return 0;
}

// function defintion
int read_int(std::string prompt)
{
    cout << prompt << endl;
    int input;
    cin >> input;
    return input;
}