class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        // basic idea after checking the constraints is to make a pre calc count array
        // then iterate the main array and pushback the values from the pre calc count array
        
        int count[101] = {};
        
        for( int i = 0 ;i < nums.size() ; i ++){
            count[nums[i]]++;                           // getting the count of values
        }
        
        for( int i = 1 ; i < 101 ; i++){
            count[i] += count[i-1];                     // pre calculation of elements smaller than 
        }
        
        
        for( int i = 0 ;i < nums.size() ; i++){
            if( nums[i] == 0){
                nums[i] =0;
            }else{
                nums[i] = count[nums[i]-1];             // gets count of element index before it 
            }
            
        }
        
        return nums;
        
    }
};