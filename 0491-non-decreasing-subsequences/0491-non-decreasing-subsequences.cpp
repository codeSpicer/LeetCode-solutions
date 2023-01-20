class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        // we will be using back tracking to generate all possible cobminations of array while generating we will
        // only give option to push or not push an element in array if it is greater or equal to the last element of array
        
        set<vector<int>> result;
        vector<int> cur;
        
        backtrack( nums , cur , result , 0);
        
        return vector( result.begin() , result.end() );
        
    }
    
    void backtrack( vector<int> nums , vector<int> cur , set<vector<int>> &result , int start){
        
        if( start == nums.size()){
            // pushing if we are on the end of array 
            // and also having more than 2 elements 
            if( cur.size() >=2){
                result.insert(cur);
            }
            return;
        }
        
        if( cur.empty() || cur.back() <= nums[start]){
            // if cur is empty we push or if the cur element is greater than last element in cur
            cur.push_back(nums[start]);
            backtrack( nums , cur , result , start+1 );
            cur.pop_back();
        }
        backtrack( nums , cur , result , start +1);
    }
};