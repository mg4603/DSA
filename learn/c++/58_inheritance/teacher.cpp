#include <iostream>
#include "teacher.h"

Teacher::Teacher()
{
    std::cout << "Teacher created.\n";
    // first calls teacher constructor and then calls user constructor
}

void Teacher::output()
{
    std::cout << "Teacher output.\n";
}