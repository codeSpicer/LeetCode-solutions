class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort( potions.begin() , potions.end());
        vector<int> ans(spells.size()); 
        
        for( int i = 0 ; i < spells.size() ; i++){
            
            //  for every spell we will try to find the index at which , its product with potions is larger than success 
            // then for all the indexes in the sorted array , next elements product will be larger too
            // so potions.size() - index will be stored in ans vector
            
            long long target = ceil( (success*1.0) / spells[i] );
            
            
            ans[i] = potions.size() - (lower_bound( potions.begin() , potions.end() , target) - potions.begin());
            
        }
        
        return ans;
        
    }
};