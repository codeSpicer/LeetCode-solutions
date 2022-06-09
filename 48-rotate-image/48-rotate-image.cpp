class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        
        int n = arr.size();
        int m = arr[0].size();
            
        
        // for matrix rotating or inverting problems we should think
        // if inverting or swapping rows can solve the problem or not 
            
        // step 1 swap rows with colums 
        // step 2 swap columns to get mirror of matrix
            
        for( int i  = 0 ; i < n ;i++){
            for( int j = i ;j < m ; j++){   // get tramspose
                int temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
            }
        }
        
        for( int i = 0; i < n ; i++){
            int a = 0;
            int b = m-1;
            while( a < b){                  // do mirror
                int temp2 = arr[i][a];
                arr[i][a] = arr[i][b];
                arr[i][b] = temp2;
                a++;b--;
            }
        }
        
    }
};