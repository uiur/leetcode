// Runtime: 24 ms, faster than 5.91% of C++ online submissions for Best Time to Buy and Sell Stock II.
// Memory Usage: 13.4 MB, less than 5.07% of C++ online submissions for Best Time to Buy and Sell Stock II.
class Solution {
public:
    unordered_map<int, int> memo;
    int subProfit(vector<int>& prices, int start) {
        if (prices.size() - start == 0) return 0;
        if (memo.find(start) != memo.end()) return memo[start];

        int min_price = prices[start];
        int max_profit = 0;
        for (int i = start; i < prices.size(); i++) {
            min_price = min(min_price, prices[i]);
            if (min_price < prices[i]) {
                int profit = prices[i] - min_price;
                max_profit = max(max_profit, profit + subProfit(prices, i + 1));
            }
        }
        memo[start] = max_profit;
        return max_profit;

    }
    int maxProfit(vector<int>& prices) {
        return subProfit(prices, 0);
    }
};
