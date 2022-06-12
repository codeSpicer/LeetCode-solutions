class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        int min_price = prices[0];
        int n = prices.size();
        
        for( int i = 1 ;i < n ;i++){
            
            // basic idea is to iterate the array and update min prices at every step
            min_price = min( min_price , prices[i]);
            
            // and also check current value - min_price to calculate current profit
            profit = max( profit , prices[i]- min_price);
            // if cur_profit is greater than profit , we update it         
        }        
        
        return profit;
    }
};