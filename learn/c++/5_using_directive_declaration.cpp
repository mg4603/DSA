#include <iostream>

// using directive
//      takes everything in std namespace and makes it available 
//      to the program
using namespace std; 

// using declaration
//      specify which object we cant to make available to the program
using std::cout;

int main()
{
    std::cout << "Using directive and declaration\n";
    return 0;
}