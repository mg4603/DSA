#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <queue>

class Solution {
// const int LIMIT = 1000000;

    std::vector<int> buildSPF(int num) {
        std::vector<int> spf(num);
        // std::vector<int> primes;

        // for (int i = 2; i < num; i++) {
        //     if (spf[i] == 0) {
        //         spf[i] = i;
        //         primes.push_back(i);
        //     }

        //     for (auto p: primes) {
        //         if (p > spf[i] || i * p >= num) {
        //             break;
        //         }
        //         spf[i * p] = p;
        //     }
        // }

        for (int i = 2; i * i < num; i++) {
            if(spf[i] == 0) {
                for (int j = i * i; j < num; j += i) {
                    if(spf[j] == 0) {
                        spf[j] = i;
                    }
                }
            }
        }

        for (int i = 2; i < num; i++) {
            if (spf[i] == 0) {
                spf[i] = i;
            }
        }
        return spf;
    }

    std::vector<int> factorize(int num, std::vector<int> &spf) {
        std::vector<int> factors;
        while (num > 1) {
            int p = spf[num];
            factors.push_back(p);
            while (num%p == 0) {
                num /= p;
            }
        }
        return factors;
    }

public:
    int minJumps(std::vector<int>& nums) {
        int limit = *std::max_element(nums.begin(), nums.end()) + 1;
        std::queue<int> q;
        q.push(0);
        std::vector<bool> visited(nums.size(), false);
        visited[0] = true;

        std::vector<int> dist(nums.size(), 0);
        std::unordered_set<int> usedPrimes;

        std::vector<int> spf = buildSPF(limit);
        std::map<int, std::vector<int>> primesToIndices;
        for (int i = 0; i < nums.size(); i++) {
            std::vector<int> factors = factorize(nums[i], spf);
            for (int factor: factors) {
                primesToIndices[factor].push_back(i);
            }
        }

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i == nums.size() - 1) {
                return dist[i];
            }

            if (i - 1 >= 0 && !visited[i - 1]) {
                dist[i - 1] = dist[i] + 1;
                visited[i - 1] = true;
                q.push(i - 1);        
            }

            if (i + 1 < nums.size() && !visited[i + 1]) {
                dist[i + 1] = dist[i] + 1;
                visited[i + 1] = true;
                q.push(i + 1);
            }

            if (nums[i] > 1 && spf[nums[i]] == nums[i] && !usedPrimes.count(nums[i])) {
                usedPrimes.insert(nums[i]);
                for (int j: primesToIndices[nums[i]]) {
                    if (!visited[j] && j != i) {
                        visited[j] = true;
                        q.push(j);
                        dist[j] = dist[i] + 1;
                    }
                }
            }
        }
        return -1;
    }
};