#ifndef USER_H
#define USER_H
#include <iostream>

class User{
    static int user_count;

    std::string first_name;
    std::string last_name;
    
    std::string status;

    public:
        static int get_user_count();

        User();

        User(std::string first_name, std::string last_name);

        ~User();

        void set_first_name(std::string first_name);

        void set_last_name(std::string last_name);

        void set_status(std::string status);
        
        std::string get_first_name();
        
        std::string get_last_name();

        std::string get_status();

        friend std::ostream& operator << (std::ostream &output, User & user);
        friend std::istream & operator >> (std::istream &input, User &user);
};

#endif