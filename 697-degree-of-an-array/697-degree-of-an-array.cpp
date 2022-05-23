class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        unordered_map< int , int > nums_count;
        unordered_map<int , int > first_occur;
        
        int degree = 0;
        int subarr = 0;
        
        for( int i= 0 ;i < nums.size() ; i++){
            
            first_occur.try_emplace( nums[i], i); 
            // enters first occurance and ignores if a value is already mapped

            
            nums_count[nums[i]]++;  // increases frequency of current number
            
            if( nums_count[nums[i]] > degree){
                
                degree = nums_count[nums[i]];   
                //if count of cur number is bigger than degree then update degree
                subarr = i - first_occur[nums[i]]+1;
                // also calculate the subarr using the current array and first occurance
            }else if( nums_count[nums[i]] == degree){
                subarr = min( subarr , i - first_occur[nums[i]]+1);
            }
        }
        
            return subarr;
        
    }
};