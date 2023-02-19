class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort( nums.begin() , nums.end() );
        set<vector<int>> s;
        // vector<vector<int>> result;
        vector<int> temp;
        
        
        backtrack( nums , s , temp , 0);
        
        vector<vector<int>> result( s.begin() , s.end());
        
        return result;
    }
    
    void backtrack( vector<int> nums , set<vector<int>> &res , vector<int> temp , int index ){
        
        if( index == nums.size() ){
            res.insert( temp);
            return;
        }
        
        backtrack( nums , res , temp , index+1);
        
        temp.push_back( nums[index]);
        backtrack( nums , res , temp , index+1);
        temp.pop_back();
        
    }
    
};