class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        // we can just get the summation of the array
        
        // then from the array iterate and substract numbers from the summation
        
        // the number we are left with at the last is the number missing from the array
        
        int total = (nums.size())*(nums.size()+1)/2;
        
        for( int i = 0 ; i < nums.size() ; i++){
            total -= nums[i];
        }
        
        return total;
        
    }
};