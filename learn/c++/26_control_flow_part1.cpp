#include <iostream>

int main()
{
    std::cout << "Control Flow: Part 1" << std::endl << std::endl;
    // branching:
    //      * if
    //      * switch    : conditional variable must be of integral type
    //                      (int, long, char, etc.)
    // 
    // looping:
    //      * while
    //      * for
    //      * do-while

    //  If Statements:
    int age;
    std::cout << "How old are you?\n";
    std::cin >> age;
    if(age < 13)
    {
        std::cout << "You're not old enough. \n";
    }
    else if(age < 19)
    {
        std::cout << "You're almost 19.\n";
    }
    else
    {
        std::cout << "You're way too old.\n";
    }

    
    std::cout << "Always, except when we return inside if" << std::endl;

    
    return 0;
}