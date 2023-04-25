class Solution {
public:
    
    int recurse( vector<int> &dp, vector<int> cost , int indx ){
        
        if( indx == 1 || indx == 0){
            return cost[indx];
        }
        
        if( dp[indx] != -1){
            return dp[indx];
        }
        
         dp[indx] = min( recurse(dp  ,cost , indx-1 ) , recurse(dp  , cost , indx-2)) + cost[indx];
        return dp[indx];
        
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp( cost.size() , -1);
        return min( recurse( dp,cost , n-1 ) , recurse(dp, cost , n-2));
        
    }
};