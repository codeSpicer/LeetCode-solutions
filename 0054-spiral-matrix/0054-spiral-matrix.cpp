class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> result;
        int size = matrix.size() * matrix[0].size();
        
        int left = 0 ; int right = matrix[0].size()-1; int top = 0 ; int bottom = matrix.size()-1;
        
        while( result.size() < size ){
            
            for( int i = left ; i <= right &&  result.size() < size  ; i++ ){
                result.push_back( matrix[top][i]);  // going right
            }
            top++;
            
            for( int i = top ; i <= bottom &&  result.size() < size  ; i++ ){
                result.push_back( matrix[i][right]);  // going down fr
            }
            right--;
            
            for( int i = right ; i >= left &&  result.size() < size  ; i-- ){
                result.push_back( matrix[bottom][i]);  // going left 
            }
            bottom--;
            
            for( int i = bottom ; i >= top &&  result.size() < size  ; i-- ){
                result.push_back( matrix[i][left]);  // going up
            }
            left++;
            
        }
        
        return result;
        
    }
};