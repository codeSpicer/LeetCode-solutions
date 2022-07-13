class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        // idea is to make 2 variables min and max 
        // we keep updating min and max by multiplying numbers of array one by one
        // when we hit a negative number we swap min and max numbers
        
        // after every element we compare max with result and current number
        // the largest number gets set as result
        
        
        int maxim = 1 , mini = 1 , result = INT_MIN;
        
        int n = nums.size() ;
        
        for( int i = 0 ; i < n ; i++){
            
            if( nums[i] < 0){
                swap( maxim , mini);           // if  cur num is -ve then min and max would change places
            }
            
            maxim = max( nums[i] , maxim * nums[i]);
            mini = min(nums[i] * mini , nums[i]);
            
            result = max( maxim  , result );
                     
        }
        
        
        return result;
        
    }
};