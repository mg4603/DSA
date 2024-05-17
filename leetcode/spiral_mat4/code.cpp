#include <iostream>
#include <assert.h>

#include "../helper/list/list.cpp"
#include <vector>
#include <array>

class Solution {
public:
    std::vector<std::vector<int>> spiralMatrix(int m, int n, 
                                        ListNode<int>* head) {
        std::ios::sync_with_stdio(0);
        std::vector<std::vector<int>> res(m, std::vector<int>(n, -1));
        int top = -1;
        int bottom = m + 1;
        int left = -1;
        int right = n + 1;

        std::array<int, 2> diff{0, 1};
        int i = 0;
        int j = 0;
        while(i < bottom && j < right && 
            i >= top && j >= left && head) {
            
            res[i][j] = head->val;
            i += diff[0];
            j += diff[1];
            if(j == right - 1 && diff[1]) {
                right--;
                j--;
                i++;
                diff[1] = 0;
                diff[0] = 1;
            }

            if(i == bottom - 1 && diff[0]) {
                bottom--;
                i--;
                j--;
                diff[0] = 0;
                diff[1] = -1;
            }

            if(i == top + 1 && diff[0]) {
                top++;
                i++;
                j++;
                diff[0] = 0;
                diff[1] = 1;
            }

            if(j == left && diff[1]) {
                left++;
                j++;
                i--;
                diff[0] = -1;
                diff[1] = 0;
            }
            head = head->next;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        int m = 3;
        int n = 5;
        ListNode<int> *head = to_list<int>(std::vector<int>{3,0,2,
                                            6,8,1,7,9,4,2,5,5,0});
        std::vector<std::vector<int>> res = {
            {3,0,2,6,8},
            {5,0,-1,-1,1},
            {5,2,4,9,7}};
        assert(sol.spiralMatrix(m, n, head) == res);
    }
    return 0;
}