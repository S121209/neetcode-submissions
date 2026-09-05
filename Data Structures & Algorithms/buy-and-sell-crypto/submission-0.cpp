class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int present = 0;
        int profit = 0;

        for (int i = 0; i < prices.size(); i++) {
            profit = max(profit, prices[i] - prices[present]);
            present = (prices[i] < prices[present]) ? i : present;
        }

        return profit;
    }
};
