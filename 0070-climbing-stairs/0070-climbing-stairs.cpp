class Solution {
public:
    int climbStairs(int n) {
        
        vector<int> dp( n+1 , -1);
        int ans = recurse( n , 0 , dp);
        
        
        return ans;
        
    }
    
    int recurse( int n  ,  int index , vector<int> &dp){
        
        if( index == n ) return 1;
        
        if( index > n ) return 0; 
        
        if( dp[index] != -1){
            return dp[index];
        }
        
        int one = recurse(n, index+1, dp);
        int two = recurse(n, index+2, dp);
        dp[index] = one + two;
        return dp[index];
        
    }
    
};