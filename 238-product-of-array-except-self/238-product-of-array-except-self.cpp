class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // so we calculate multiplicative prefix and suffix of an array and then 
        // we multiply those 2 to find the product of numbers except current number
        
        // to solve it in o(1) space excluding result array
        // we can store the result of prefix or suffix in output array first
        // then we can use a variable and iterate from opposite side to update the array
        
        int n = nums.size();
        vector<int> result(n);
        
        result[0] = 1;
        
        for( int i = 1 ; i < n ; i++){
            result[i] = result[i-1]* nums[i-1];       // stores product of left elements first
        }
        
        int prod = 1;       // continuously updates and stores product of right elements
        
        for( int i = n-2 ; i >=0; i--){
            prod *= nums[i+1];
            result[i]*= prod;
        }
        
        
        return result;
        
    }
};