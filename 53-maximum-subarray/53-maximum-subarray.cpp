class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int max_so_far = INT_MIN;
        int cur_max = 0;
        
        for( int i = 0 ;i < nums.size() ; i++){
            
            cur_max += nums[i];
            if( cur_max > max_so_far){
                    max_so_far = cur_max;
            }
            if( cur_max <= 0){
                cur_max = 0;
            }
            
        }
        
        return max_so_far;
        
    }
};