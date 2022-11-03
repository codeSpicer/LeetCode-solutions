class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        // calling a recursive function which once calls by inserting the current index element form 
        // vector then pops it out and calls it again 
        // calls it self recursively till current index == list size then pushes in result vector
        
        vector<vector<int>> result;
        vector<int> temp;
        
        backTrack( result , nums , temp , 0);
        
        return result;
                
    }
    
    void backTrack( vector<vector<int>> &result , vector<int> nums , vector<int> &temp , int index ){
        
        if( index == nums.size() ){
            result.push_back(temp);
            return;
        }
        
        backTrack( result , nums , temp , index + 1);
        temp.push_back(nums[index]);
        backTrack( result , nums , temp , index + 1);
        temp.pop_back();
                
    }
    
};