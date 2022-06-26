class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        // the main problem is to solve this in place o(n) space
        
        // if we see the constraints we can see the numbers do no exceed 1000 mark
        
        // so we can store 2 numbers at one index by multiplying and adding the second number with 1000 
        // and adding to the first index
        
        // later on we can retrive the 2 numbers by 1) doing modulo with 1000 and 2) doing division with 1000
        
        int multiplier = 1024;      // 2^x for ocd and 32 bit int overflow when 1000*1024
        
        // to store all numbers in right half of original array
        for( int i = n ; i < 2*n ; i++){
            
            nums[i] = ( nums[i]* multiplier ) + nums[i-n];
            
        }
        
        // to retrive values and form ans 
        int index = 0;
        
        for( int i = n ; i < 2*n ;i++ , index +=2){
            
            nums[index] = nums[i] % multiplier;         // getting the x value 
            nums[index+1] = nums[i] / multiplier;    // getting the y value 
            
        }        
        
        return nums;
    }
};