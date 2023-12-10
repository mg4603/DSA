#include <iostream>
#include <assert.h>

#include <unordered_set>
#include <queue>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minMutation(std::string start, std::string end, 
                    std::vector<std::string>& bank) 
    {
        if(std::find(bank.begin(), bank.end(), end) == bank.end())
        {
            return -1;
        }
        std::string gene_chars = "ACGT";
        std::unordered_set<std::string> visited;
        std::unordered_set<std::string> bank_st(bank.begin(), 
                                                bank.end());
        std::queue<std::pair<std::string, int>> q;
        q.push(std::make_pair(start, 0));

        
        while(!q.empty())
        {
            
            std::pair<std::string, int> it = q.front();
            q.pop();
            int level = it.second;
            std::string gene = it.first;
            visited.insert(gene);
            if(gene == end)
            {
                return level;
            }

            for(int i = 0; i < 8; i++)
            {
                for(char c: gene_chars)
                {
                    std::string new_gene = gene.substr(0, i) + c + 
                                                gene.substr(i + 1);

                    if(visited.find(new_gene) == visited.end() && 
                        bank_st.find(new_gene) != bank_st.end())
                    {
                        q.push(std::make_pair(new_gene, level + 1));
                    }
                }
            }

        }
        return -1;
    }
};

int main()
{
    Solution sol;
    {
        std::string startGene = "AACCGGTT";
        std::string endGene = "AACCGGTA";
        std::vector<std::string> bank = {"AACCGGTA"};
        int res = 1;
        assert(sol.minMutation(startGene, endGene, bank) == res);
    }
    {
        std::string startGene = "AACCGGTT";
        std::string endGene = "AAACGGTA";
        std::vector<std::string> bank = {"AACCGGTA",
                                         "AACCGCTA",
                                         "AAACGGTA"};
        int res = 2;
        assert(sol.minMutation(startGene, endGene, bank) == res);
    }
    return 0;
}