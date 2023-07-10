#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

int read_int(std::string prompt)
{
    cout << prompt << endl;
    int input;
        cin >> input;
    return input;
}

int main()
{
    cout << "In functions part3" << endl;
    // function call
    //      * enter the name of the function followed by parentheses
    //      * put the arguments required separated by comma inside the parentheses
    //      * arguments can be literals, expression(including other function calls)
    //        and variables 
    cout << pow(10, 2) << endl;

    int base = read_int("What is the base?");
    int exponent = read_int("What is the exponent?");

    double power = pow(base, exponent);
    cout << power <<endl;
    return 0;
}