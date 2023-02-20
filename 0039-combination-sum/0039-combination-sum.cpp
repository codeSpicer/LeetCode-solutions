class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> result;
        vector<int> temp;
        
        backtrack( candidates , result , target , 0 , temp , 0);        /// maagiiikkk
        
        return result;
        
        
    }
    
    void backtrack(vector<int> candidates , vector<vector<int>> &res , int target , int cursum , vector<int> temp , int index){
        
        // pick or not pick 
        // pick till we are less than target val
        
        if( cursum > target){
            return;     // terminating condition
        }
        if( index == candidates.size()){
            return;     // ter cond part 2
        }
        if( cursum == target ){
            res.push_back(temp);        // add to answer condition
            return;
        }
        
        // not pick
        backtrack( candidates , res , target , cursum , temp , index+1);
        
        // pick
        cursum += candidates[index];
        temp.push_back(candidates[index]);
        backtrack( candidates , res , target , cursum , temp , index);
        temp.pop_back();
        
        
    }
    
    
};