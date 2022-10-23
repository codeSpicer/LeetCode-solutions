class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        // swapping the current value to its index and marking that index as negative
        // then if we fall on negative index again it means that number comes twice
        // we can increment pointer for numbers that are in place
        
        int miss , dup ;
        
        for( const auto& i : nums){
            
            if( nums[abs(i)-1] < 0){
                dup = abs(i);              // if current number 
            }else{
                nums[ abs(i)-1 ] *= -1;     // we make the current number's index sign negative
            }
            
        }
        
        for( int i = 0 ; i < nums.size() ; i++){
            if( nums[i] > 0){
                miss = i+1;
            }
        }
        
        return vector<int>{ dup , miss};        
        
    }
};