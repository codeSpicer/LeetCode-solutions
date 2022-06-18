class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        // greedy approach
        // we iterate from the end of the array
        // taking the last element as target
        // if the element before it can reach the target element then we make that previous element the target
        // if the target is accessible from first index then first index will become target
        
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