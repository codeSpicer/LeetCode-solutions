class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        // the basic idea of this solution is to count the number of zeros 
        // and is a non zero number arrives then we swap it with its index - no of zeros
        
        //     0 1 0 2 12    -> in this case when we go on index 1 we swap it with 1-1 ==0
        //     1 0 0 2 12    -> similarly when we arive at index 3 the zero count is 2 so 
        //     we swap it with index 3-2 ==1
        //      and so on
        
        int zeros = 0;
        
        for( int i = 0 ; i< nums.size() ; i++){
            
            if( nums[i] != 0){
                swap( nums[i] , nums[i - zeros]);
            }else{
                zeros++;
            }
            
        }
        
    }
};