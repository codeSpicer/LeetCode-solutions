class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // so we calculate multiplicative prefix and suffix of an array and then 
        // we multiply those 2 to find the product of numbers except current number
        
        int n = nums.size();
        vector<int> result(n);
        
        vector<int> pre(n) ;
        pre[0]=1;
        vector<int> post(n);
        post[n-1]=1;
        
        for( int i = 1 ; i < n ; i++){
            pre[i] = pre[i-1]* nums[i-1];
        }
        
        for( int i = n-2 ; i >=0; i--){
            post[i] = post[i+1]*nums[i+1];
        }
        
        result[0]= post[0];
        result[n-1]= pre[n-1];
        
        for( int i = 1; i < n-1 ; i++){
            result[i] = pre[i]* post[i];
        }
        
        return result;
        
    }
};