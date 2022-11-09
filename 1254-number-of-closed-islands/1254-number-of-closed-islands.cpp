class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        // will flood fill all the islands connected to boundary with 1
        // then count the number of islands remaining 
        
        int res = 0;
        
        for( int r = 0 ; r < grid.size() ; r++){            // filling the boundary islands with water
            for( int c = 0 ; c < grid[0].size() ; c++){
                if( r*c == 0 || r == grid.size() -1 || c == grid[0].size()-1 ){
                    floodfill( grid , r , c);
                }
            }
        }
        
        for( int r = 0 ; r < grid.size() ; r++){        // counting the left islands 
            for( int c = 0 ; c < grid[0].size() ; c++){
                if( grid[r][c] == 0 ){
                    res++;
                    floodfill( grid , r , c);
                }
            }
        }
        
        return res;       
        
    }
    
    void floodfill( vector<vector<int>> &grid , int r , int c){
        if( r >= grid.size() || r < 0 || c >= grid[0].size() || c < 0 || grid[r][c] == 1 ){
            return;
        }
        grid[r][c] =1;
        
        floodfill( grid , r-1 , c);
        floodfill( grid , r , c-1);
        floodfill( grid , r+1 , c); 
        floodfill( grid , r , c+1);
        
    }
    
    
};