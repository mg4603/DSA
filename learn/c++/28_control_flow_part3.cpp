#include <iostream>

int main()
{
    std::cout << "Control Flow Part 3: Switch statement and Enum\n\n";
    // Switch statement
    //      * check for equality 
    //      * other types of logical comparisons can't be made
    //      * parameter to be checked has to be an integral type
    //      * if break or return isn't used at the end of the case block
    //        the next case block is executed (code exec. falls through)
    // 
    // enum:
    //      * stores possible values as integers
    //      *  enum Class can be used to scope enum 
    // 
    int option;
    std::cout << "Choose an option(1-4): \n";
    std::cin >> option;
    switch(option)
    {
        case 1:
            std::cout << "You choose option 1\n";
            break;
        case 2:
            std::cout << "You choose option 2\n";
            break;
        case 3:
            std::cout << "You choose option 3\n";
            break;
        case 4:
            std::cout << "You choose option 4\n";
            break;
        default:
            std::cout << "Invalid option\n";
            break;
    }

    std::cout << std:: endl;

    enum season{summer, spring, autumn, winter};
    season now = autumn;
    switch(now)
    {
        case summer:
            std::cout << "It's summer now.\n";
            break;

        case spring:
            std::cout << "It's spring now.\n";
            break;

        case autumn:
            std::cout << "It's autumn now.\n";
            break;

        case winter:
            std::cout << "It's winter now.\n";
            break;
        default:
            std::cout << "Such a season doesn't exist\n";
            break;
    }

    std::cout << std::endl;

    enum class Days{monday, tuesday, wednesday, thursday, friday, saturday, sunday};
    Days day = Days::monday;
    switch(day)
    {
        case Days::monday:
            std::cout << "Today is Monday.\n";
            break;
        case Days::tuesday:
            std::cout << "Today is Tuesday.\n";
            break;
        case Days::wednesday:
            std::cout << "Today is Wednesday.\n";
            break;
        case Days::thursday:
            std::cout << "Today is Thursday.\n";
            break;
        case Days::friday:
            std::cout << "Today is Friday.\n";
            break;
        case Days::saturday:
            std::cout << "Today is Saturday.\n";
            break;
        case Days::sunday:
            std::cout << "Today is Sunday.\n";
            break;
        default:
            std::cout << "That's not a day of the week.\n";
            break;
    }
    return 0;
}