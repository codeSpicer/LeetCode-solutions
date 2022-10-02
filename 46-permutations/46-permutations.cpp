class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // we can swap elements of array one by one 
        // we can keep a pointer to store index of traverse array
        
        // [1 , 2 , 3]
        //  first call recursively by locking one [ 1 , 2 , 3 ]  and [1 , 3 , 2]    when we swap further more
        
        vector<vector<int>> result;
        recurse( nums , result , 0);
        return result;
    }
    
    void recurse( vector<int> &nums , vector<vector<int>> &result , int begin){
        
        if( begin == nums.size() -1){
            result.push_back( nums);         // if swapping index has reached the size of array then no more elements can be swapped to make more permutations
        }
        
        for( int i = begin ; i < nums.size() ; i++){
            
            swap( nums[begin] , nums[i]);       // we swap all the elements one by one with begin
            recurse(nums , result , begin+1);   // call recuse with begin +1 to make new combinations
            swap( nums[begin] , nums[i]);       // reset the array
            
        }
        
        
        
    }
    
    
};