class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        
        int max_difference = INT_MIN;
        int min_ele = nums[0];
        
        for(int i = 1 ; i< nums.size() ; i++){
            
            min_ele = min( min_ele , nums[i]);
            max_difference = max( max_difference , nums[i]-min_ele );
            
        } 
        if( max_difference <1){
            return -1;
        }
        return max_difference;
        
    }
};