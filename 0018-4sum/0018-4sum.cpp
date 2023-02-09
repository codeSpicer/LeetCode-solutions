class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        // first step is to sort the array 
        
        sort( nums.begin() , nums.end() );
        vector<vector<int>> result;
        int size = nums.size();
        
        for( int i = 0 ; i < size ; i++ ){
            
            // because we fixed one element we substract it from target
            long target_1 = target - nums[i];
            
            for( int j = i+1 ; j < size ; j++ ){
                
                // subtract second element from target because element fixed
                long target_2 = target_1 - nums[j];
                
                // now int he rest of the sorted array we use 2 pointer approach to make target 0
                int left = j+1;
                int right = size-1;
                
                while( left < right ){
                    
                    long sum = nums[left] + nums[right];
                    
                    if( target_2 - sum > 0){
                        left++;
                    }else if( target_2 - sum < 0){
                        right--;
                    }else{
                        
                        result.push_back( vector<int> {nums[i] , nums[j] , nums[left] , nums[right]});
                        
                        //to avoid same answers in result , we skipp the same elements from left & right
                        while( left < size-2 && nums[left] == nums[left+1]){
                            left++;
                        }
                        while( right > 1 && nums[right] == nums[right-1] ){
                            right--;
                        }
                        left++; right--;
                    }
                    
                }
                
                while( j < size-2 && nums[j] == nums[j+1]){
                    j++;
                }
                
            }
            
            while( i < size-2 && nums[i] == nums[i+1]){
                    i++;
                }
            
        }
        
        return result;
        
        
    }
};