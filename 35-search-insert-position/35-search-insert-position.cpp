class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        

        int high = nums.size()-1;
        int low = 0;
        
        if( target > nums[high]){
            return nums.size();
        }
        if( target <= nums[0]){
            return 0;
        }
        
        while ( low < high ){
            
            int mid = low + (high -low)/2;
            
            if( nums[mid] < target){
                low = mid+1;
            }else{
                high = mid;
            }
            
        }
        
        return low;
        
    }
};