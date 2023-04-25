class Solution {
public:
    /*
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
    */
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp( cost.size() , -1);
        
        //return min( recurse( dp,cost , n-1 ) , recurse(dp, cost , n-2));
        
        for( int i = 0 ; i < n ; i++){
            if( i < 2 ) dp[i] = cost[i];
            else{
                dp[i] = min( dp[i-1] , dp[i-2])+ cost[i];
            }
        }
        
        return min(dp[n-1],dp[n-2]);
        
    }
};