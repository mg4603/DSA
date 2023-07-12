#include <iostream>

int main()
{
    std::cout << "Strings Part2" << std::endl;
    // User input
    //      * cin object with >> operator - only gets input upto the 
    //                                      first white space
    //                                    - the remainder is stored in the
    //                                      input stream
    //      * getline with cin object - multi-word user input
    //              * getline(std::cin, identifier) ==> for strings
    //              * cin.getline() ==> all types of inputs; created before the 
    //                                  string class chronologically
    // 

    std::string user_input;
    std::cout << "Enter some input: " << std::endl;
    std::cin >> user_input;
    std::cout << "User input: " << user_input << std::endl;

    std::string left_over_user_input;
    std::cin >> left_over_user_input;
    std::cout << "Left over user input: " << left_over_user_input << 
                std::endl << std::endl;

    std::cout << "Enter some multi-word input: " << std::endl;
    std::cin >> std::ws; // due to mixing of cin with operator and getline
    std::string multi_word_user_input;
    getline(std::cin, multi_word_user_input);
    std::cout << "Multi-word user input: " <<  multi_word_user_input << 
                std::endl << std::endl;


    return 0;
}