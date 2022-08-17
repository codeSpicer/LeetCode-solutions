class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        //  1 7 3  6  5  6 
        //  1 8 11 17 22 28     ---> running sum from right
        //  28 27 20 17 11 6    ---> running sum from left
        
        // so the value of index 3 is same in both the arrays and 3 is the answer
        
        int ans = -1;
        int n = nums.size()-1;
        
        vector<int> right(n+1);
        vector<int> left(n+1);
        
        right[0] = nums[0];
        left[n] = nums[n];
        
        for( int i = 1 ; i < nums.size() ; i++){
            right[i] = nums[i] + right[i-1];
        }
        
        for( int i = n-1 ; i >= 0 ; i--){
            left[i] = nums[i] + left[i+1];
        }
        
        for( int i = 0 ; i <= n ; i++ ){
            if( left[i] == right[i]){
                ans = i;
                break;
            }
        }
        
        return ans;
        
    }
};