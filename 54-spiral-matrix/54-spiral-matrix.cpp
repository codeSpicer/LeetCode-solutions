class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> result;
        int goal = matrix.size() * matrix[0].size();
        
        int left = 0 , right = matrix[0].size() -1, top = 0 , bottom = matrix.size() -1;
        
        while( result.size() < goal){
            
            for( int i = left ; i <= right && result.size() < goal ; i++  ){
                result.push_back( matrix[top][i]);
            }
            
            for( int i = top +1 ; i <= bottom && result.size() < goal ; i++){
                result.push_back( matrix[i][right] );
            }
            
            for( int i = right -1 ; i >= left && result.size() < goal ; i--){
                result.push_back( matrix[bottom][i]);
            }
            
            for( int i = bottom -1 ; i > top &&  result.size() < goal ; i-- ){
                result.push_back( matrix[i][left]);
            }
            
            top++; left++; bottom --;right--;
        }
        
        return result;
        
    }
};