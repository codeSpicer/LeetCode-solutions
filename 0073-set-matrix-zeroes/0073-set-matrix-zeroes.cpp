class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        bool cols = false;
        
        for( int i = 0 ; i < matrix.size() ; i++){
            
            if( matrix[i][0] == 0 ){
                cols = 1;
            }
            for( int j = 1 ; j < matrix[0].size() ; j++){
                if( matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        
        for (int i = 1; i < matrix.size(); i++) {
          for (int j = 1; j < matrix[0].size(); j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
              matrix[i][j] = 0;
            }
          }
        }

        // See if the first row needs to be set to zero as well
        if (matrix[0][0] == 0) {
          for (int j = 0; j < matrix[0].size(); j++) {
            matrix[0][j] = 0;
          }
        }

        // See if the first column needs to be set to zero as well
        if (cols) {
          for (int i = 0; i < matrix.size(); i++) {
            matrix[i][0] = 0;
          }
        }
        
    }
};