class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int size = n*n;
        int num = 1;
        
        int left = 0; int right = n-1 ; int top = 0 ; int bottom = n-1;
        
        vector<vector<int>> res(n , vector<int> (n));
        
        while( num <= size ){
            
            for( int i = left ; i <= right ; i++ ){
                res[top][i] = num++;
            }
            top++;
            
            for( int i = top ; i <= bottom ; i++){
                res[i][right] = num++;
            }
            right--;
            
            for( int i = right ; i >= left ; i--){
                res[bottom][i] = num++;
            }
            bottom--;
            
            for( int i = bottom ; i >= top ; i--){
                res[i][left] = num++;
            }
            left++;
            
        }
        
        return res;
    }
};