#include <iostream>
#include <assert.h>

#include <vector>

auto fast = []() {
    std::ios::sync_with_stdio(0);
    return 1;
}();
class Cashier {
    int n;
    int curr;
    int discount;
    std::vector<int> prods;
public:
    Cashier(int n, int discount, std::vector<int>& products, 
                                std::vector<int>& prices) {
        curr = 0;
        this->discount = discount;
        this->n = n;
        prods.resize(201);
        for(int i = 0; i < products.size(); i++) {
            prods[products[i]] = prices[i];
        }
    }
    
    double getBill(std::vector<int> product, 
                    std::vector<int> quantity) {
        curr++;
        double bill = 0.0;
        for(int i = 0; i < product.size(); i++) {
            bill += prods[product[i]] * quantity[i];
        }
        if(curr == n) {
            bill *= (100.0 - discount) / 100.0;
            curr = 0;
        }
        return bill;
    }
};

int main()
{
    std::vector<int> products = {1,2,3,4,5,6,7};
    std::vector<int> prices = {100,200,300,400,300,200,100};
    Cashier cashier(3,50, products, prices);
    assert(cashier.getBill({1,2},{1,2}) == 500.0);
    assert(cashier.getBill({3,7},{10,10}) == 4000.0);
    assert(cashier.getBill({1,2,3,4,5,6,7},{1,1,1,1,1,1,1}) == 800.0);
    assert(cashier.getBill({4},{10}) == 4000.0);
    assert(cashier.getBill({7,3},{10,10}) == 4000.0);
    assert(cashier.getBill({7,5,3,1,6,4,2},{10,10,10,9,9,9,7}) == 7350.0);
    assert(cashier.getBill({2,3,5},{5,3,2}) == 2500.0);
    return 0;
}