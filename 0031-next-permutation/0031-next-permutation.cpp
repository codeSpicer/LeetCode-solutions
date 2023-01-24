class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        for( int i = nums.size()-2 ; i >=0 ; i-- ){
            int index = i+1;
            if( nums[i] < nums[i+1]){
                for( int j = i+1 ; j < nums.size() ; j++ ){
                    if( nums[j] > nums[i]){
                        index = j;
                    } 
                }
                swap( nums[i] , nums[index]);
                sort( nums.begin() + i+1 , nums.end());
                return;
            }
        }
        sort( nums.begin() , nums.end());
    }
};