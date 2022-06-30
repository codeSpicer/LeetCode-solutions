class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
        int n = nums.size();
        int i = 0;
        int j = 1;
        
        while( i < n){

            while( i < n && !(nums[i] & 1) ){
                i+=2;
            }
            while( j < n && (nums[j] & 1) ){
                j+=2;
            }            
            if( i < n){
                swap( nums[i] , nums[j]);
            }
        }
        
        return nums;
        
    }
};