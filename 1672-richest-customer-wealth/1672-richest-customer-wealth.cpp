class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int maxMone = 0;
        int curMone = 0;
        
        for( int i = 0 ;i < accounts.size() ; i ++){
            
            for( int j = 0 ; j < accounts[0].size() ; j++){
                
                curMone += accounts[i][j];
                
            }
            
            maxMone = max( curMone ,  maxMone);
            curMone = 0;
            
        }
        
        return maxMone;
        
    }
};