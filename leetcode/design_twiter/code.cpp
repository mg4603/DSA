#include <iostream>
#include <assert.h>

#include <vector>
#include <algorithm>
#include <unordered_map>

class Twitter {
    std::unordered_map<int, std::vector<int>> tweets;
    std::unordered_map<int, std::vector<int>> follows;
    std::unordered_map<int, int> order;
    int tweet_no;
public:
    Twitter() {
        tweet_no = 0;
    }
    
    void postTweet(int userId, int tweetId) 
    {
        if(tweets.count(userId) == 0)
        {
            tweets[userId] = {};
        }
        tweets[userId].push_back(tweetId);
        order[tweetId] = tweet_no++;

    }
    
    std::vector<int> getNewsFeed(int userId) 
    {
        std::vector<int> res = tweets[userId];

        for(int i = 0; i < follows[userId].size(); i++)
        {
            std::vector<int> temp = tweets[follows[userId][i]];
            res.insert(res.end(), temp.begin(), temp.end());
        }

        std::sort(res.begin(), res.end(), [&](auto a, auto b)
        {
            return order[a] > order[b];
        });
        while(res.size() > 10)
        {
            res.pop_back();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) 
    {
        if(follows.count(followerId) == 0)
        {
            follows[followerId] = {};
        }    
        if(std::find(follows[followerId].begin(), 
                     follows[followerId].end(), followeeId) != 
            follows[followerId].end())return;

        follows[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) 
    {
        if(follows.count(followerId) != 0)
        {
            auto it = std::find(follows[followerId].begin(), 
                                follows[followerId].end(), followeeId);
            follows[followerId].erase(it);
        }    
    }
};

int main()
{
    Twitter obj;
    obj.postTweet(1, 5); 
    assert(obj.getNewsFeed(1) == std::vector<int>({5}));
    obj.follow(1, 2);    
    obj.postTweet(2, 6); 
    assert(obj.getNewsFeed(1) == std::vector<int>({6, 5}));
    obj.unfollow(1, 2);  
    assert(obj.getNewsFeed(1) ==  std::vector<int>({5}));
    return 0;
}