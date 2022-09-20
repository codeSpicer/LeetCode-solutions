class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        // increase counter by 1 for every 1 encountered and when encountered by 1
        // we run a funciton recursively to change 1 on all 4 sides 0 zero 
        // so that the island becomes all water 
        
        int counter = 0;
        
        for( int i = 0 ; i < grid.size() ; i++){
            for( int j = 0 ; j < grid[0].size() ; j++){
                
                if( grid[i][j] == '1'){
                    counter++;
                    turnZero( grid , i , j);
                }
                
            }
        }
        
        return counter;
        
    }
    
    void turnZero( vector<vector<char>>& grid , int i , int j ){
        
        if( i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0' ){
            return;
        }else{
            grid[i][j] = '0';
            turnZero( grid , i -1 , j);
            turnZero( grid , i +1 , j);
            turnZero( grid , i , j+1);
            turnZero( grid , i , j-1);
        }
        return;
    }
    
};