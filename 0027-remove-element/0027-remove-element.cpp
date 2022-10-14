class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        // gonna use 2 pointer approach 
        // one from start another from end
        // if we find val on i then we swap with j ptr and move ONLY j--
        // then swap the values of both pointers 
        // till i < j
        
        int i = 0 ;
        int j = nums.size() -1;
        
        while( i <= j ){
            
            if( nums[i] == val){
                swap( nums[i] , nums[j]);
                j--;
            }else{
                i++;
            }
            
        }
        
        return i; // dumb question statement tabhi dislikes itne saare
        
    }
};