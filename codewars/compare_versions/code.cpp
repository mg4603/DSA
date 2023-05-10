#include <iostream>
#include <assert.h>

#include <string>
#include <vector>

std::vector<int> parseVersion(std::string &version){
    int idx(0);
    std::vector<int> version_vec;
    while(version.find('.', idx) != std::string::npos){
        int pos(version.find('.', idx));
        version_vec.push_back(stoi(version.substr(idx, pos - idx)));
        idx = pos + 1;
    }
    version_vec.push_back(stoi(version.substr(idx)));
    return version_vec;
}

bool compareVersions (std::string version1, std::string version2) {

    if(version1 == version2)
    {
        return true;
    }

    std::vector<int> version1_vec = parseVersion(version1);
    std::vector<int> version2_vec = parseVersion(version2);

    bool version2_greater(0);
    
    int n(std::min(version1_vec.size(), version2_vec.size()));
    for(size_t i(0); i < n; i++){
        if(version1_vec[i] > version2_vec[i]){
            return true;
        }
        else if(version2_vec[i] > version1_vec[i])
        {
            version2_greater = true;
            break;
        }
    }
    
    if(!version2_greater && version1_vec.size() > version2_vec.size())
    {
        return true;
    }

    return false;
}

void testing_versions_without_subversion()
{
    assert(compareVersions("11", "10") == true);
}
void test_equal_versions()
{
    assert(compareVersions("11", "11") == true);
}
void adding_a_subversion_should_make_this_version_larger()
{
    assert(compareVersions("10.4.6", "10.4") == true);
}
void subversion_precedence_is_smaller_than_Version()
{
    assert(compareVersions("10.4", "11") == false);
}
void version_value_is_not_the_same_as_its_decimal_value()
{
    assert(compareVersions("10.4", "10.10") == false);
}
void adding_subversion_does_not_make_it_larger_than_a_greater_version()
{
    assert(compareVersions("10.4.9", "10.5") == false);
}

int main()
{
    adding_subversion_does_not_make_it_larger_than_a_greater_version();
    testing_versions_without_subversion();
    test_equal_versions();
    adding_a_subversion_should_make_this_version_larger();
    subversion_precedence_is_smaller_than_Version();
    version_value_is_not_the_same_as_its_decimal_value();

}