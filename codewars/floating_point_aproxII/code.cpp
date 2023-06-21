#include <iostream>
#include <assert.h>

#include <cmath>
#include <string>
#include <iomanip>
#include <chrono>
#include <random>
#include <sstream>

#include <vector>
#include <cmath>

namespace App
{
    template<typename Func>
    std::vector<double> interp(Func f, double l, double u, int n)
    {
        std::vector<double> sol(n);
      
        double d((u-l) / static_cast<double>(n));
      
        for(double i(0); i < n; i ++)
        {
          sol[i] = floor(f(l + i * d) * 100.0) / 100.0;
        }
        return sol;
    }
}

namespace Helper{
    static std::string join(std::vector<double> ans)
    {
        std::stringstream ss;
        ss << '{';
        for(size_t i(0); i < ans.size(); i++)
        {
            if(i > 0)
                ss << ", ";
            std::string temp(std::to_string(ans[i]));
            ss << temp.substr(0, temp.find('.') + 3);
        }
        ss << '}';
        return ss.str();
    }
};

void testingFixed(std::vector<double> ans, std::string sol1)
{
    std::string ans1 = Helper::join(ans);
    assert(ans1 == sol1);
}
static void dotestFixed1(double l, double u, int n, std::string sol)
{
    std::cout << "interp with f : x -> x\n";
    auto lambda = [] (double x) { return x; };
    testingFixed(App::interp(lambda, l, u, n), sol);
}
static void dotestFixed2(double l, double u, int n, std::string sol)
{
    std::cout << "interp with f : x -> sin(x)\n";
    auto lambda = [] (double x) { return sin(x); };
    testingFixed(App::interp(lambda, l, u, n), sol);
}
static void dotestFixed3(double l, double u, int n, std::string sol)
{
    std::cout << "interp with f : x -> cos(x)\n";
    auto lambda = [] (double x) { return cos(x); };
    testingFixed(App::interp(lambda, l, u, n), sol);
}

int main()
{
    std::cout << "Tests 1st series\n";
    dotestFixed1(0.0, 9.0, 4, "{0.00, 2.25, 4.50, 6.75}");
    dotestFixed1(0.0, 15.0, 9, "{0.00, 1.66, 3.33, 5.00, 6.66, 8.33, 10.00, 11.66, 13.33}");
    
    std::cout << "Tests 2nd series\n";
    dotestFixed2(0, 18.0, 12, "{0.00, 0.99, 0.14, -0.98, -0.28, 0.93, 0.41, -0.88, -0.54, 0.80, 0.65, -0.72}");
    dotestFixed2(0, 21.0, 10, 
            "{0.00, 0.86, -0.88, 0.01, 0.85, -0.88, 0.03, 0.84, -0.89, 0.05}");

    std::cout << "Tests 3rd series\n";
    dotestFixed3(0, 21.0, 7, 
            "{1.00, -0.99, 0.96, -0.92, 0.84, -0.76, 0.66}");
    dotestFixed3(0, 15.0, 12, 
            "{1.00, 0.31, -0.81, -0.83, 0.28, 0.99, 0.34, -0.79, -0.84, 0.25, 0.99, 0.37}");        
}