class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // many diff approaches like 
        //divide and conq by finding majority of 2 halfes ,
        // hashmap to store counter of elements 
        // sort and find max
        
        // optimal solution is using moores voting algorithm
        
        int majority_element= nums[0];
        int votes=1;
        
        for( int i = 1 ; i < nums.size() ; i++ ){
            
            if( nums[i] == majority_element ){
                votes++;                // if current ele is maj then votes go up
            }else{
                votes--;        // if cur ele is not maj then votes of maj -1
                
                if(votes < 1){
                    majority_element = nums[i];        // if maj votes go below 1 
                    votes = 1;                         // we form a new majority element and give one vote
                }
                
            }
            
        }       // if there if a majortiy element then that element will have a vote count > 0;
        
        return majority_element;
        
    }
};