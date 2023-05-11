class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        // https://leetcode.com/problems/longest-common-subsequence/        // solve this before for better idea
        
        vector<vector<int>> dp( nums1.size()+1 , vector<int> (nums2.size()+1 , 0));
        
        for( int i = 0 ; i < nums1.size() ;i++){
            for( int j = 0 ; j < nums2.size() ; j++){
                
                if( nums1[i] == nums2[j]){
                    dp[i+1][j+1] = 1 + dp[i][j];
                }else{
                    dp[i+1][j+1] = max( dp[i+1][j] , dp[i][j+1]);
                }
                
            }
        }
        
        return dp[nums1.size()][nums2.size()];
        
    }
};