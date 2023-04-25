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
        
        return recurse( dp , nums , nums.size()-1 );
        
    }
};