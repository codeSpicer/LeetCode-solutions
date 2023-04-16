class Solution {
public:    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        set<vector<int>> ans;       // stores non duplicate combos
        vector<int> temp ;          // temp array
        sort( candidates.begin() , candidates.end());   // sorting the original array so we can skip the same values
        
        backtrack( candidates , target , 0 , temp , ans);
        
        vector<vector<int>> result( ans.begin() , ans.end() ) ;     // transfering all the elements from set to resultant vector
        return result;        
        
    }
    
    void backtrack( vector<int> candidates , int target , int index , vector<int> &temp , set<vector<int>>& ans){
        
        if( target == 0){
            ans.insert( temp);  // add to answer and return
            return;
        }
        
        for( int i = index ; i < candidates.size() ; i++){
            
            if( i > index && candidates[i] == candidates[i-1]) continue;        // TO AVOID TAKING SAME ELEMENTS IN THE ANS AGAIN  
            if( target -candidates[i] < 0) break;          // OPTIMIZATION // IF ELEMENT IS GREATER THAN TARGET THEN ALL UPCOMING ELEMENTS ARE INVALID
            
            temp.push_back( candidates[i]);
            backtrack( candidates , target-candidates[i] , i+1 , temp , ans);   // to pick or not to pick
            temp.pop_back();
        }        
    }
    
};