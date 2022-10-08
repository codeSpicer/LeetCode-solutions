class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        // similar to 3sum problem 
        // we do not need indexes of elements so we sort the array then lock one element at a time 
        // and use 2 pointer to find an element closed to the target element
        // if the 3 numbers sum is close to target then we update result
        
        // -1 , 2 , 1 , -4
        // -4 , -1 , 1 , 2
        // 
        
        sort( nums.begin() , nums.end() );
        
        int closest;
        int diff = INT_MAX;
        
        for( int i = 0 ; i < nums.size()-2 ; i ++){   // for locked element index
            
            int j = i+1 ;     // front pointer 
            int k = nums.size()-1;  // back pointer
            
            
            while( j < k ){
                
                // closest = min( closest , abs( target - (nums[i]+ nums[j] + nums[k]) ) );
                
                if( abs( target - (nums[i]+ nums[j] + nums[k])) < diff){
                    closest = nums[i]+ nums[j] + nums[k];
                    diff = abs( target - (nums[i]+ nums[j] + nums[k]));
                }
                
                if( diff == 0){
                    return closest;
                }
                
                if( (nums[i]+ nums[j] + nums[k]) > target ){
                    k--;
                }else{
                    j++;
                }
                
            }
            
        }
        
        return closest;
        
    }
};