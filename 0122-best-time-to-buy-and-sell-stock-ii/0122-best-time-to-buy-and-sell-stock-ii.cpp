class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0 , buy , sell , i = 0;
        int n = prices.size()-1;
        
        while( i < n ){
            
            while( i < n && prices[i] >= prices[i+1] ){
                i++;
            }
            buy = prices[i];
            
            while( i < n && prices[i] < prices[i+1]){
                i++;
            }
            sell = prices[i];
            
            profit += sell-buy;
            
        }
        return profit;
    }
};