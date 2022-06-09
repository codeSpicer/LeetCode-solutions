class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector< vector<int>> arr(n,vector<int>(n));

        int count = 1;
        
        // we fill in values layer by layer 
        
        for( int layer = 0 ; layer < n/2+1 ; layer++){
            
            // going right
            for( int i = layer ; i < n-layer ;i++){
                arr[layer][i] = count++;
            }
            
            // going down
            for( int i = layer+1; i < n-layer ; i++){
                arr[i][n-1-layer] = count++;
            }
            
            //going left
            for( int i = n-layer-2 ; i >= layer ; i--){
                arr[n-layer-1][i] = count++;
            }
            
            // going up 
            for( int i = n-layer-2 ; i > layer ; i--){
                arr[i][layer] = count++;
            }
            
        }
        return arr;
    }
};