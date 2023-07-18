#include "user.h"

int User::get_user_count()
{
    return user_count;
}

User::User()
{
    this->status = "Gold";
    user_count++;
}

User::User(std::string first_name, std::string last_name)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->status = "Gold";
    user_count++;

}

User::~User()
{
    user_count--;
}

void User::set_first_name(std::string first_name)
{
    this->first_name = first_name;
}    

void User::set_last_name(std::string last_name)
{
    this->last_name = last_name;
}

void User::set_status(std::string status)
{
    this->status = status;
}

std::string User::get_first_name()
{
    return this->first_name;
}

std::string User::get_last_name()
{
    return this->last_name;
}

std::string User::get_status()
{
    return this->status;
}

std::ostream& operator << (std::ostream &output, User & user)
{
    output << "\tFirst name: " << user.first_name << std::endl;
    output << "\tLast name: " << user.last_name << std::endl;
    output << "\tStatus: " << user.status;
    return output;
}

std::istream & operator >> (std::istream &input, User &user)
{
    input >> user.first_name >> user.last_name;
    return input;
}


int User::user_count = 0;