class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        // one approach would be to use count sort but 2 pass
        
        // for 1 pass we make 3 pointers low mid high
        // low mid will be at index 0 and high at n.size
        
        int low = 0;
        int mid = 0;
        int high = nums.size()-1;
        
        while( mid <= high){
            
            if( nums[mid] == 0 ){
                swap( nums[low] , nums[mid]);
                low++; mid++;
            }else if( nums[mid] == 2 ){
                swap( nums[high] , nums[mid]);
                high--;
            }else{
                mid++;
            }
            
        }
    }
};