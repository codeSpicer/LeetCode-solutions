class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        vector<vector<int>> result;
        
        for( int i = 0 ; i < board.size() ; i++ ){
            
            vector<int> row;
            
            for( int j = 0 ; j < board[0].size() ; j++){
                
                int count = getCount( board , i , j );
                
                if( count  < 2 ){
                    row.push_back(0);
                }else if(board[i][j] == 0 && count == 2){
                    row.push_back(0);
                }else if( count == 2 || count == 3){
                    row.push_back(1);
                }else if( count > 3 ){
                    row.push_back(0);
                }
                
            }
            
            result.push_back(row);
            row.resize(0);
            
        }
        
        board = result;
        
    }
    
    
    int getCount( vector<vector<int>> curr , int i , int j ){
        
        
        int m = curr.size();
        int n = curr[0].size();
        
        
        int liveNeighbours = 0;
	if(i>0) {
		//check the upper neighbour
		if(curr[i-1][j] == 1) liveNeighbours++;
	}
	if(i<m-1) {
		//check the lower neighbour
		if(curr[i+1][j] == 1) liveNeighbours++;
	}
	if(j>0) {
		//check the left neighbour
		if(curr[i][j-1] == 1) liveNeighbours++;
	}
	if(j<n-1) {
		//check the right neighbour
		if(curr[i][j+1] == 1) liveNeighbours++;
	}

	if(i>0 && j>0) {
		if(curr[i-1][j-1] == 1) liveNeighbours++;
	}
	if(i>0 && j<n-1) {
		if(curr[i-1][j+1] == 1) liveNeighbours++;
	}
	if(i<m-1 && j>0) {
		if(curr[i+1][j-1] == 1) liveNeighbours++;
	}
	if(i<m-1 && j<n-1) {
		if(curr[i+1][j+1] == 1) liveNeighbours++;
	}
	return liveNeighbours;
        
    }
    
};