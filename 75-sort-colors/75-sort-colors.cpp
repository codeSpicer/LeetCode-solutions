class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        
        // idea is to use dnf sorting 
        // we make 3 pointers low mid and high
        // 0-low we have 0
        // low to mid we have 1 
        // mid to high we have 2
        
        // low and mid start from 0 , high starts from end of array
        // we iterate mid and high 
        
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
