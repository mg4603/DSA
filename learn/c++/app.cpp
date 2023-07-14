#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

bool already_guessed(std::vector<int> guesses, int guess)
{
    for(int i(0); i < guesses.size(); i++)
    {
        if(guesses[i] == guess)
        {
            return true;
        }
    }
    return false;
}

void print_vector(std::vector<int> data)
{
    for(int i(0); i < data.size(); i++)
    {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
}

void play_game1()
{
    std::vector<int> guesses;

    int random(rand() % 251);
    std::cout << "Guessing Game\n\n";
    while(true)
    {
        int guess;
        std::cout << "Guess a number between 0 and 250\n";
        std::cin >> guess;

        if(already_guessed(guesses, guess))
        {
            std::cout << "Already guessed that number! Try again.\n";
            continue;
        }
        guesses.push_back(guess);
        
        if(guess == random)
        {
            std::cout << "Congratulation! You win.\n\n";
            break;
        }
        else if(guess > random)
        {
            std::cout << "Too high! Try again.\n";
        }
        else
        {
            std::cout << "Too low! Try again.\n";
        }
    }

    std::cout << "Guesses Made: ";
    print_vector(guesses);
    std::cout << std::endl;
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