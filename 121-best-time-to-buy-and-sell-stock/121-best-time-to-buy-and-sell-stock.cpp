class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int max_profit = 0;
        int min_price = INT_MAX;
        int size = prices.size();    
        
        for( int i = 0 ;i < size ; i++){
            
            min_price = min(prices[i],min_price);
            max_profit = max(max_profit,prices[i]-min_price);
            
        } 
        
        return max_profit;
        
        
    }
};