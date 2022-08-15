class Solution {
public:
    
    void reverse(vector<int> &nums, int start) {
        int i = start, j = nums.size() - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }

    void swap(vector<int> &nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size()-2;
        int i = n;
        
        // first we find the decreasing element from the end of array
        while( i >=0 && nums[i+1] <= nums[i] ){
            i--;
        }
        // now nums[i] is decreasing element or  it is the first element in array
        
        // we need to find the slightly bigger element for the rhs of the ith index
        if( i >=0){
            int j = nums.size()-1;
            while( nums[j] <= nums[i] ){
                j--;
            }
            swap(nums , i , j);     //we swap the number just bigger than ith num 
        }
        reverse( nums , i+1);       // at last we reverse nums from ith index to end to make 
                                    // the number smallest bigger number
    }
};