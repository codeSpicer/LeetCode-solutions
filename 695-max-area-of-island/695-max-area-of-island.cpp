class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int max_area = 0;
        // vector<vector<bool>> seen;
        
        for( int i = 0 ;i < grid.size() ; i++){
            for( int j = 0 ; j < grid[0].size() ;j++){
                if( grid[i][j] == 1){
                    max_area = max( max_area , area_cal(grid, i , j ));
                }
            }
        } 
        
        return max_area;
        
    }
    
    int area_cal(vector<vector<int>>& grid  , int i , int j ){
        
        if( i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] ==0){
            return 0;
        }                   // checking for boundary conditions and also if the place has water 
        
        // seen[i][j]=1;// mark as seen 
        grid[i][j] = 0;
        
        // calling function recursively for 4 sides 
        // depth first search
        // returning 1 + 1 for each side it has land on 
        return 1 + area_cal(grid , i+1 , j ) + area_cal(grid , i-1 , j) + area_cal(grid , i , j+1) + area_cal(grid , i , j-1);
        
    }
};