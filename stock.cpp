#include <iostream>
#include <vector>
using namespace std;
// Mental model: the best profit is: today's price - cheapest price seen so far
// Wrong Mental model: the best profit is: minimum price which index is before the max global price
int maxProfit(vector<int>& prices) {
    if(prices.size() < 2){return 0;}

    int mn = prices[0];
    int profit = 0;

    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] <= mn) {
            mn = prices[i];
        }
        int todaysDeal = prices[i] - mn;
        if(profit < todaysDeal){
            profit = todaysDeal;
        }
        if(profit < 0){
            return 0;
        }
    }
    return profit;
}

int main() {
    vector<int> prices = {3,15,1,14};
    cout << "Max profit is: " << maxProfit(prices) << endl;
    return 0;
}