class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l = 0;
        int r = nums.size()-1;
        
        // 4    5   6   7   0   1   2
        
        // so if we think then pivot would lie in one side of the array at all times
        // so we check for the sorted part of the array every time and if the sorted part contains the 
        // target element we move l and r to sorted part
        // else we more the lr to parts where the pivot is and repeat again ;
        
        while( l <= r){
            
            int mid = ( l+r)/2;
            
            if( nums[mid] == target){       /// if target found
                return mid;
            }
            
            if( nums[l] <= nums[mid]){       // if left is sorted
                if( nums[l] <= target && nums[mid] > target){       // target in left side
                    r = mid-1;
                }else{                                              // target not in left side
                    l = mid+1;
                }
            }else{                          // if right part is sorted
                if( nums[mid] < target && nums[r] >= target){     // target in right side
                    l = mid+1;
                }else{                                              // target not in right side
                    r = mid-1;
                }
                
            }
            
            
        }
        return -1;
    }
};