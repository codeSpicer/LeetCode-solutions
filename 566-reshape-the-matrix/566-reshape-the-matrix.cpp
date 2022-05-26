class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r2, int c2) {
        
        int r1 = mat.size();
        int c1 = mat[0].size();
        
        if( (r1 * c1) != (r2 * c2) ){       // checking for valid output matrix
            return mat;
        }
        
        int rows = 0;
        int cols = 0;
        
        // initialising defined size vector with 0s
        vector<vector<int>> ans( r2 , vector<int>( c2 , 0));
        
        for( int i = 0 ; i< r1 ; i++){
            for( int j = 0 ; j < c1 ; j++){     // looping through the original array
                
                ans[rows][cols] = mat[i][j];
                
                cols++;
                if( cols == c2){                // putting elements in ans arr one by one
                    cols = 0;                   // when cols reach c2 then we go to next row 
                    rows++;
                }
            }
        }
        
        return ans;
        
        
    }
};