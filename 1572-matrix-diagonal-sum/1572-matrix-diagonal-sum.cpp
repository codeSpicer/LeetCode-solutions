class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int result = 0;
        
        for( int i = 0 ; i < mat.size() ; i++){
            
            result += mat[i][i] + mat[i][mat.size()-i-1];
            if( i == mat.size()-i-1){
                result -= mat[i][i];
            }
            
        }
        
        return result;
    }
};