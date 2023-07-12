// Logical and comparison operators
#include <iostream>

int main()
{
    std::cout << "Control Flow Part 2: logical and comparison operators\n\n";

    // comparison
    //      * == : check for equality
    //      * != : check for inequality
    //      * <  : less than
    //      * >  : greater than
    //      * <= : less than or equal to
    //      * >= : greater than or equal to
    // 
    // logical
    //      * && : and
    //      * || : or
    //      * !  : not
    // 
    int ans = 25;
    int guess(-1);
    std::cout << "Guess the number:\n\t* greater than 0\n\t* 3 tries\n";
    int tries = 0;
    while(guess != ans && tries < 10)
    {
        std::cin >> guess;
        if(guess > ans)
        {
            std::cout << "Too High! Try again." << std::endl;
        }
        else if(guess < ans)
        {
            std::cout << "Too Low! Try again." << std::endl;
        }
        tries++;
    }

    if(tries <= 3 && guess == ans)
    {
        std::cout << "Congratulations! You win." << std::endl;
    }
    else if(tries < 10 && guess == ans)
    {
        std::cout << "You guessed the answer in " << tries << " tries.\n" << std::endl;
    }
    else
    {
        std::cout << "You lost!" << std::endl;
    }
    std::cout << std::endl;
    return 0;
}