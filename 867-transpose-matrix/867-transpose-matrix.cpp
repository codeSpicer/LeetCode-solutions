class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        // initializing rows with cols and cols with rows
        vector<vector<int>> transpose( matrix[0].size() , vector<int> (matrix.size()));
        
        for( int i = 0 ; i < matrix.size() ; i++){
            for( int j = 0 ; j < matrix[0].size() ; j++){
                transpose[j][i] = matrix[i][j];     // swaping indexes of 2 matrices to make transpose
            }
        }
        return transpose;
    }
};