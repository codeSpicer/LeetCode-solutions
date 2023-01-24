class Solution {
public:
    int triangularSum(vector<int>& nums) {
        
        vector<int> temp( nums.size());
        
        while( nums.size() > 1){
            for( int i = 0  ; i < nums.size()-1 ; i++){
                temp[i] = (nums[i]+nums[i+1])%10;
            }
            temp.pop_back();
            nums = temp;
        }
        return nums[0];
    }
};