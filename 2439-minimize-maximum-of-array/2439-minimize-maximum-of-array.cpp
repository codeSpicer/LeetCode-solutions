class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {

        long long total = nums[0];
        int res = nums[0];
        
        for( int i = 1 ; i < nums.size() ; i++){
            total += nums[i];
            // res = max( res , ceil( total / (i+1) ));
            if( res < ceil( 1.0*total/(i+1))){
                res = ceil( 1.0*total/(i+1));
            }
        }
        return res;   
    }
};