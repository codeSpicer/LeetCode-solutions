class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> numbers ;
        
        for( int i = 0 ;i < nums.size() ; i++){
            
            if( numbers.find(nums[i]) == numbers.end()){
                numbers.insert( nums[i]);
            }else{
                return 1;
            }
            
        }
        return 0;
    }
};