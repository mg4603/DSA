#include <iostream>
#include <assert.h>

#include <cmath>

class Solution {
  int nextNumber(int num)
  {
    int new_number(0);
    while(num)
    {
      new_number += std::pow(num % 10, 2);
      num /= 10;
    }
    return new_number;
  }
public:
    bool isHappy(int n) {
        int first_pointer = nextNumber(n);
        int second_pointer = n;
        while(first_pointer != 1 && first_pointer != second_pointer)
        {
          first_pointer = nextNumber(nextNumber(first_pointer));
          second_pointer = nextNumber(second_pointer);
        }
        return first_pointer == 1;

    }
};

int main()
{
    Solution sol;
    {
        assert(sol.isHappy(19) == true);
    }
    {
        assert(sol.isHappy(2) == false);
    }
    return 0;
}