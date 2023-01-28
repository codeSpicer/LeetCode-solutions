class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int candi = nums[0];
        int votes = 1;
        
        for( int i = 1 ; i < nums.size() ; i++){
            if( candi == nums[i]){
                votes++;
            }else{
                votes--;
            }
            if( votes == 0){
                candi = nums[i];
                votes = 1;
            }
        }
        return candi;
    }
};