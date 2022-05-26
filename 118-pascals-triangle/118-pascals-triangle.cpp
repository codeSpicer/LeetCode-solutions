class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector< vector<int>> ans_arr( numRows , vector<int>( numRows , 0));
        
        ans_arr[0][0] = 1;
        
        ans_arr[0].resize(1);
        
        for( int i = 1 ; i < numRows ; i++){
            
            ans_arr[i].resize(i + 1);
            
            for( int j = 0 ; j < numRows ; j++){
                             
                if( j == 0){
                    ans_arr[i][j] = ans_arr[i-1][j];
                }else{
                    ans_arr[i][j] = ans_arr[i-1][j] + ans_arr[i-1][j-1];
                }
                
            }
        }
        
        return ans_arr;
        
    }
};