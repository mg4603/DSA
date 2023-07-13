#include <iostream>

int main()
{
    int choice;

    do{
        std::cout << "0. Quit\n1. Play Game\n";
        std::cin >> choice;

        switch (choice)
        {
        case 0:
            std::cout << "Thanks for nothing\ns";
            break;
        case 1:
            std::cout << "Game 1\n";
            break;
        default:
            break;
        }

    }while(choice != 0);

    return 0;
}