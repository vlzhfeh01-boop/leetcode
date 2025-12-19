#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /* My answer, Time exceeded with leetcode TEstCase.
         if(is_sorted(prices.begin(),prices.end(),greater<int>())){
            return 0;
        }
        int max_profit = 0 ;
        int temp_profit = 0;
        int n_days = prices.size() - 1;
        int min_price_day = prices[0];
        for (int i = 0; i< n_days; i++){
            if (min_price_day >= prices[i]){
                min_price_day = prices[i];
                for(int j = i+1; j<=n_days; j++){
                    if(prices[i] < prices[j]){
                        temp_profit = prices[j] - prices[i];
                        if(temp_profit > max_profit){
                            max_profit = temp_profit;
                        }
                    }
                }
            }
        }
        return max_profit; */

        // Ans.
        int buy = prices[0];
        int profit = 0;
        for(int i = 1; i<prices.size(); i++){
            if(prices[i] < buy){
                buy = prices[i];
            }
            else if(prices[i]-buy > profit){
                profit = prices[i] - buy;
            }
        }
        return profit;
    }
};

int main(){

    class Solution sol1;

    vector<int> prices = {7,1,5,3,6,4};

    int max = sol1.maxProfit(prices);
    cout << max << endl;
    return 0;
}