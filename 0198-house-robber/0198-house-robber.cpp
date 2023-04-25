class Solution {
private:
    int recurse( vector<int> &dp , vector<int> nums , int n ){
        
        if( n < 0){
            return 0;
        }
        
        if( n == 0){
            return nums[n];
        }
        
        if( dp[n] != -1){
            return dp[n];
        }
        
        // pick 
        int pick = recurse(dp , nums , n-2 )+ nums[n];
        
        // not pick
        int not_pick = recurse(dp , nums , n-1 ); 
        
        dp[n] = max( pick , not_pick);
        
        return dp[n];
        
    }
    
    
public:
    int rob(vector<int>& nums) {
        
        vector<int> dp( nums.size() , -1);
        
        // return recurse( dp , nums , nums.size()-1 );
        
        // to make a tabulation from memorization we fill up the base case first in the dp 
        // then from the bottom case we fill up the table
        
        dp[0] = nums[0];
        
        for( int i = 1 ; i < nums.size() ; i++){
            int take =  nums[i] ;
            if( i > 1 ){
                take += dp[i-2];    // if we are taking the cur element then the element 2 steps behind can also be taken
            }
            
            int not_take = 0 + dp[i-1];
            
            dp[i] = max( take , not_take);
        }
        
        return dp[dp.size()-1];
    }
};