class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        
        int max1= INT_MIN;
        int max2 = INT_MIN;
        int max_index = -1;
        
        
        for( int i = 0 ;i < nums.size() ; i++){
            
            if( nums[i] > max1){
                max2 = max1;
                max1 = nums[i];
                max_index = i;
            }else if( nums[i] > max2){
                max2 = nums[i];
            }
            
        }
        
        if( max1 >= max2 * 2 ){
            return max_index;
        }
        return -1;
    }
};