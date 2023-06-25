#include <assert.h>
#include <iostream>

#include <vector>
#include <map>

std::vector<std::vector<int> *> bucketize(const std::vector<int> &a)
{
    std::vector<std::vector<int> *> res(a.size() + 1, nullptr);

    std::map<int, int> mp;
    for(const int num: a)
    {
        if(mp.count(num) == 0)
        {
            mp[num] = 0;
        }
        mp[num]++;
    }

    for(auto ele: mp)
    {
        if(res[ele.second] == nullptr)
        {
            res[ele.second] = new std::vector<int>();
        }
        res[ele.second]->push_back(ele.first);
    }

    return res;
}

 void doTest(const std::vector<int> &a, const std::vector<std::vector<int>> &exp)
{
    std::vector<std::vector<int> *> expected, actual = bucketize(a);
    for (auto v : exp) expected.push_back(v.size() ? new std::vector<int>(v) : NULL);
    if ( actual.size() != expected.size() )
    {
        std::cout << "Vector sizes don't match.\n"
                << "Expected " << expected.size() << " elements.\n"
                << "Received " << actual.size() << " elements." << std::endl;
        assert(actual.size() == expected.size());
    }
    for (int i = 0; i < (int)expected.size(); i++)
    {
        if ( actual[i] && expected[i] )
        {
            if ( actual[i]->size() != expected[i]->size() )
            {
                std::cout << "Vector sizes don't match for count of " << i << ".\n"
                        << "Expected " << expected[i]->size() << " elements.\n"
                        << "Received " << actual[i]->size() << " elements." << std::endl;
                assert(actual[i]->size() == expected[i]->size());
            }
            for (int j = 0; j < (int)expected[i]->size(); j++)
                if ( (*actual[i])[j] != (*expected[i])[j] )
                {
                    std::cout << "Vectors for count of " << i << " don't match." << std::endl;
                    // assert(*actual[i], EqualsContainer(*expected[i]);
                }
        }
        else if ( !actual[i] && expected[i] )
        {
            std::cout << "Expected a vector for count of " << i << ", but received a NULL." << std::endl;
            assert(true == false);
        }
        else if ( actual[i] && !expected[i] )
        {
            std::cout << "Expected a NULL for count of " << i << ", but received a vector." << std::endl;
            assert(true == false);
        }
    }
    for (auto v : actual)   if ( v ) delete v;
    for (auto v : expected) if ( v ) delete v;
}

void should_return_an_array_with_a_length_of_input_length_plus_one()
{
    std::vector<int> a = {4,5,6};
    std::vector<std::vector<int> *> actual = bucketize(a);
    assert(actual.size() == a.size() + 1);
    for (auto v : actual) if ( v ) delete v;
    a = {7,7,7,7,8,6};
    actual = bucketize(a);
    assert(actual.size() == (a.size() + 1));
    for (auto v : actual) if ( v ) delete v;
}
void should_solve_the_first_sample_test_case()
{
    doTest({1,1,1}, {{}, {}, {}, {1}});
}
void should_solve_the_second_sample_test_case()
{
    doTest({7,6,6}, {{}, {7}, {6}, {}});
}
void should_solve_the_third_sample_test_case()
{
    doTest({5,5,5,9}, {{}, {9}, {}, {5}, {}});
}
void should_solve_the_fourth_sample_test_case()
{
    doTest({8,8,4,4}, {{}, {}, {4, 8}, {}, {}});
}
void should_solve_the_fifth_sample_test_case()
{
    doTest({1,7,7,7,7,10}, {{}, {1,10}, {}, {}, {7}, {}, {}});
}
void should_solve_the_sixth_sample_test_case()
{
    doTest({20, 40, 60, 80, 100, 20}, {{}, {40, 60, 80, 100}, {20}, {}, {}, {}, {}});
}
void should_solve_the_seventh_sample_test_case()
{
    doTest({9,9,9,9,4,34,65,17}, {{}, {4, 17, 34, 65}, {}, {}, {9}, {}, {}, {}, {}});
}
void should_solve_the_eighth_sample_test_case()
{
    doTest({12,12,12,12,12,12,19,19}, {{}, {}, {19}, {}, {}, {}, {12}, {}, {}});
}
void should_solve_the_nineth_sample_test_case()
{
    doTest({1,1,1,2,3,5,5,5,5,4}, {{}, {2, 3, 4}, {}, {1}, {5}, {}, {}, {}, {}, {}, {}});
}
void should_solve_the_tenth_sample_test_case()
{
    doTest({7,6,4,3,3,3,3,3,3,2}, {{}, {2, 4, 6, 7}, {}, {}, {}, {}, {3}, {}, {}, {}, {}});
}


int main()
{
    should_return_an_array_with_a_length_of_input_length_plus_one();
    should_solve_the_first_sample_test_case();
    should_solve_the_second_sample_test_case();
    should_solve_the_third_sample_test_case();
    should_solve_the_fourth_sample_test_case();
    should_solve_the_fifth_sample_test_case();
    should_solve_the_sixth_sample_test_case();
    should_solve_the_seventh_sample_test_case();
    should_solve_the_eighth_sample_test_case();
    should_solve_the_nineth_sample_test_case();
    should_solve_the_tenth_sample_test_case();
    return 0;
}