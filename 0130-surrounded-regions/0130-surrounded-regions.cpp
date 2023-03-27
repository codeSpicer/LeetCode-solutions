class Solution {
public:
    
    vector<int> dir = { 1 , 0 , -1 , 0 , 1};
    void solve(vector<vector<char>>& board) {
        
        vector<vector<bool>> visited( board.size() , vector<bool> (board[0].size() , false));
        
        
        // first we mark all the nodes connected to the boundary as visited
        // by doing bfs on the nodes which are on the boundary and also connected 'o's with them
        // then we traverse the matrix if the 'o' is not visited we change it to x
        
        for( int i = 0 ; i < board.size() ; i++){
            for( int j = 0 ; j < board[0].size() ; j++){
                if( board[i][j] == 'O'){
                    if( i == 0 || j == 0 || i == board.size()-1 || j == board[0].size() -1 ){
                        dfsVisit( board , visited , i , j);
                    }
                }

            }
        }
        
        for( int i = 0 ; i < board.size() ; i++){
            for( int j = 0 ; j < board[0].size() ; j++){
                if( board[i][j] == 'O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
    
    void dfsVisit( vector<vector<char>>& board , vector<vector<bool>>& visited , int row , int col ){
        
        if( row >= 0 && col >= 0 && row < board.size() && col < board[0].size() && !visited[row][col] && board[row][col] == 'O'){
         
            visited[row][col] = 1;
        
            for( int i = 0 ; i < 4 ;i++){

                dfsVisit( board , visited , row + dir[i] , col+ dir[i+1] );

            }
            
        }
        
    }
};