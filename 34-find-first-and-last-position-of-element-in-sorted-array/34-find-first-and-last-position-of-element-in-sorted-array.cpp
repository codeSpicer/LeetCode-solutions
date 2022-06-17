class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> result;
        
        result.push_back( first_occur(nums , target));
        result.push_back( last_occur( nums , target));
        
        return result;
        
    }
    
    int first_occur( vector<int>& nums, int target){
        
        int index = -1;
        
        int low = 0;
        int high = nums.size()-1;
        
        while( low <= high){
            
            int mid = ( low + high )/2;
            
            if( nums[mid] >= target){      // two cases when we wanna go left 
                high = mid-1;               // if num is == target we still wanna go left and check 
            }else{
                low = mid+1;                  
            }
            
            if( nums[mid]== target){ index = mid;};  // update index if we encounter target
            
        }
        return index;
        
    }
    
    int last_occur(vector<int>& nums, int target){
        
        int index = -1;
        int low = 0;
        int high = nums.size()-1;
        
        while( low <= high ){
            
            int mid = ( low + high )/2;
            
            if( nums[mid] <= target){   // we will be moving right even if we find element because 
                low = mid+1;            // we need to find its last occurance
            }else{
                high = mid-1;
            }
            if( nums[mid] == target ){ index = mid;}
        }
        return index;
    }
    
    
};