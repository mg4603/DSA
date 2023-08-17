#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

struct comparator
{
    bool operator()(std::vector<int> const &a, std::vector<int> const &b) const
    {
        return a.size() > b.size(); 
    }
};

std::vector<int> merge(std::vector<int> a , std::vector<int> b)
{
    std::vector<int> res;
    int i(0);
    int j(0);
    while(i < a.size() && j < b.size())
    {
        if(a[i] < b[j])
        {
            res.push_back(a[i++]);
        }
        else
        {
            res.push_back(b[j++]);
        }
    }
    while(i < a.size())
    {
        res.push_back(a[i++]);
    }
    while(j < b.size())
    {
        res.push_back(b[j++]);
    }
    return res;
}

std::pair<std::vector<std::pair<int, int>>, std::vector<int>> optimal_merge(
    std::vector<std::vector<int>> &vec)
{
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, comparator> pq(
        vec.begin(), vec.end()
    );

    std::vector<std::pair<int, int>> merge_seq;

    while(pq.size() > 1)
    {
        std::vector<int> one = pq.top();
        pq.pop();
        std::vector<int> two = pq.top();
        pq.pop();
        merge_seq.push_back(std::make_pair(one.size(), two.size()));
        pq.push(merge(one, two));
    }

    return std::make_pair(merge_seq, pq.top());
}

int main()
{
    std::vector<std::vector<int>> vec = {
        {1, 2, 3, 4},
        {1, 2, 3},
        {1, 2},
        {1, 2, 3, 4, 5, 6}
    };
    std::pair<std::vector<std::pair<int, int>>, std::vector<int>> res = optimal_merge(vec);
    std::cout << "Merges:\n";
    for(auto merge: res.first)
    {
        std::cout << merge.first << ' ' << merge.second << std::endl;
    }
    std::cout << "Resultant vec:\n";
    for(int num: res.second)
    {
        std::cout << num << ' ';
    }
    std::cout << std::endl;
    return 0;
}