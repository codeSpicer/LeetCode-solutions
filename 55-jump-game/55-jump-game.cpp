class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size()-1;
        int target = n;
        
        
        for( int i = n-1 ; i >=0 ; i--){
            if( nums[i] + i >= target){
                target = i;
            }
        }
        
        if( target == 0){
            return true;
        }
        return false;
        
    }
};