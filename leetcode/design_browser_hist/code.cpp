#include <iostream>
#include <assert.h>

#include <stack>

class BrowserHistory {
    std::stack<std::string> history;
    std::stack<std::string> future;
    std::string current;

public:
    BrowserHistory(std::string homepage) {
        history.push(homepage);
    }
    
    void visit(std::string url) {
        history.push(url);
        while(future.size())future.pop();
    }
    
    std::string back(int steps) {
        while(steps-- > 0 && history.size() > 1)
        {
            future.push(history.top());
            history.pop();
        }
        return history.top();
    }
    
    std::string forward(int steps) {
        while(steps-- > 0 && future.size() > 0)
        {
            history.push(future.top());
            future.pop();
        }
        return history.top();
    }
};

int main()
{
    BrowserHistory browserHistory("leetcode.com");
    browserHistory.visit("google.com");       
    browserHistory.visit("facebook.com");     
    browserHistory.visit("youtube.com");      
    assert(browserHistory.back(1) == "facebook.com");
    assert(browserHistory.back(1) == "google.com");
    assert(browserHistory.forward(1) == "facebook.com");
    browserHistory.visit("linkedin.com");     
    assert(browserHistory.forward(2)  == "linkedin.com");
    assert(browserHistory.back(2) == "google.com");
    assert(browserHistory.back(7) == "leetcode.com");

    return 0;
}