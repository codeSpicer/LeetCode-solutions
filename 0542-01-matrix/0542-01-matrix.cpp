class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        vector<vector<bool>> vis( mat.size() , vector<bool> ( mat[0].size() , false));
        vector<vector<int>> res( mat.size() , vector<int> ( mat[0].size() , INT_MAX ));
        vector<int> dir = { -1 , 0 , 1 , 0 , -1 };
        
        
        queue<pair<int,int>> q;
        
        for( int i = 0 ; i < mat.size() ; i++){
            for( int j = 0 ; j < mat[0].size() ; j++){
                if( mat[i][j] == 0){
                    q.push( { i , j});          // first we push all indexes with 0 to queue
                }
            }
        }
        
        int distance = 0;
        
        while( !q.empty() ){
            
            int size = q.size();        // for every level we do a bfs starting from 0s 
            
            while( size--){
                
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                vis[row][col] = true;
                if( res[row][col] > distance){
                    res[row][col] = distance;
                }
                
                for( int i = 0 ;  i < 4 ; i++){         // calling bfs for all neighbouring nodes
                    if( row + dir[i] < mat.size() && row + dir[i] >= 0 && col+dir[i+1] < mat[0].size() && col+dir[i+1] >= 0){       // checking for out of bound erros
                        if( !vis[row+dir[i]][col+dir[i+1]] && mat[row+dir[i]][col+dir[i+1]]== 1){       // putting neighbour nodes if they have not yet begin visited and are 1 
                            q.push( { row+dir[i] , col+dir[i+1]}); 
                        }
                    } 
                }
                
            }
            distance++; // increase distance for the next layer of bfs
        }
        
        return res;
        
    }
};