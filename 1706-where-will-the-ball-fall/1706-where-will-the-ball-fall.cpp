class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        // for every pos in matrix we need to check 
        //  - if ball is going right then is the right box also going right else the ball will be struck        same for if ball goin left
        
        //  - also need to check if ball is going in bounds of 0 & n-1 
        
        int cols = grid[0].size();
        int rows = grid.size();
        
        vector<int> result;
        
        for( int i = 0 ; i < cols ; i++){
            
            int r = 0 ; int c = i;
            
            while( c >= 0  && c < cols){
                
                if( r == rows ){
                    result.push_back(c);        // if ball reaches the bottom
                    break;
                }
                
                if( grid[r][c] == 1 ){      // if ball going right
                    
                    if( c < cols-1 ){
                        if( grid[r][c+1] == 1){
                            c++;r++;
                        }else{
                            result.push_back(-1);     // path closed for going down
                            break;
                        }             
                    }else{
                        result.push_back(-1);       // into the right wall
                        break;
                    }
                    
                }else{                  // ball going left
                    
                    if( c > 0 ){
                        if( grid[r][c-1] == -1){
                            c--;r++;
                        }else{
                            result.push_back(-1);     // path closed for going down
                            break;
                        }             
                    }else{
                        result.push_back(-1);       // into the left wall
                        break;
                    }
                    
                }
                
            }
            
        }
        return result;
    }
};