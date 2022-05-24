class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // relatively easy problem if we just compare and merge the 2 arrays using 2 pointer approach
        
        // optimal way to merge is to do is from the end of nums1 as there is free space there
        
        
        int i = m-1 ;       // last ele of arr 1
        int j = n-1 ;       // last ele of arr 2
        
        int k = i +j +1 ;    // free space in arr1 
            
        while( j >= 0){     // only need to put the values from nums2 in nums1 
            
            if( i>=0 && nums1[i] >= nums2[j] ){     // the i>=0 here checks if the nums1 arr is finised and if it is then it puts all the remaining elements from the nums2 arr into nums1 using the else condition
                nums1[k] = nums1[i];
                i--;
            }else{
                nums1[k] = nums2[j];
                j--;
            }
            
            k--;
            
        }
        
    }
};