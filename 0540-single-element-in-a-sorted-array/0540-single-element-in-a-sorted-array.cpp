class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int temp = nums[0];
        
        for( int i = 1 ; i < nums.size() ; i++){
            temp ^= nums[i];
        }
        
        return temp;
        
    }
};