#include <iostream>
#include <cstdlib>
#include <ctime>

void play_game1()
{
    int random(rand() % 251);
    std::cout << "Guessing Game\n\n";
    while(true)
    {
        int guess;
        std::cout << "Guess a number between 0 and 250\n";
        std::cin >> guess;
        if(guess == random)
        {
            std::cout << "Congratulation! You win.\n\n";
            break;
        }
        else if(guess > random)
        {
            std::cout << "Too high!\n";
        }
        else
        {
            std::cout << "Too low!\n";
        }
    }
}

int main()
{
    srand(time(NULL));
    int choice;
    do{
        std::cout << "0. Quit\n1. Play Game\n";
        std::cin >> choice;

        switch (choice)
        {
        case 0:
            std::cout << "\nThanks for nothing!\ns";
            break;
        case 1:
            play_game1();
            break;
        default:
            break;
        }

    }while(choice != 0);

    return 0;
}