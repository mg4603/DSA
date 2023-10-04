#include <iostream>
#include <assert.h>

#include <unordered_set>
#include <vector>
#include <algorithm>

class Solution {
public:
    int numUniqueEmails(std::vector<std::string>& emails) {
        std::unordered_set<std::string> unique_emails;

        for(std::string email: emails)
        {
            int pos(email.find_first_of("@"));
            std::string domain(email.substr(pos));
            std::string local_name(email.substr(0, pos));

            int local_pos(local_name.find("+"));
            if(local_pos != std::string::npos)
            {
                local_name = local_name.substr(0, local_pos);
            }
            local_name.erase(
                    std::remove(local_name.begin(), local_name.end(), '.'), 
                    local_name.end()
                );
            unique_emails.insert(local_name + domain);
        }
        return unique_emails.size();
    }
};

int main()
{
    Solution sol;
    {
        std::vector<std::string> emails = 
            {
                "test.email+alex@leetcode.com",
                "test.e.mail+bob.cathy@leetcode.com",
                "testemail+david@lee.tcode.com"
            };
        assert(sol.numUniqueEmails(emails) == 2);
    }
    {
        std::vector<std::string> emails = 
            {
                "a@leetcode.com",
                "b@leetcode.com",
                "c@leetcode.com"
            };
        assert(sol.numUniqueEmails(emails) == 3);
    }
    return 0;
}