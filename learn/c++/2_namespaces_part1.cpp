#include <iostream>

int main()
{
    // namespace
    //      * grouping of code 
    //      * prevents naming conflicts:
    //          functions in different namespaces can have the same name
    //      eg: std
    // cout needs to be prefixed with std in-order to tell the compiler
    // that cout is a part of the standard namespace
    // 
    // entire namespace can be introduced into the file with 
    // using namespace <namespace name>;
    // generally bad practice as it causes naming conflicts.
    std::cout << "Namespaces part 1\n";
    return 0;
}