class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        // we can do a bfs first we put all the rotten oranges in a queue
        // then we continue to add neighbour hood oranges to queue and marking they rotten 
        // on every cycle we increment time counter by one , by cycle i mean for every new layer of oranges
        
        queue<pair<int,int>> q;
        vector<int> dir={-1,0,1,0,-1}; 
        int fresh = 0;
        
        for( int i = 0 ; i < grid.size() ; i++ ){
            for( int j = 0 ; j < grid[0].size() ; j++ ){
                if( grid[i][j] == 2){
                    q.push( { i , j});
                }else if( grid[i][j] == 1 ){
                    fresh++;
                }
                
            }
        }
        
        int ans = -1;
        
        while( !q.empty() ){
            
            int size = q.size();
            
            while( size--){
                
                pair<int,int> p = q.front();
                q.pop();
                
                for(  int i = 0 ; i < 4 ; i++){
                    
                    int r = p.first + dir[i];
                    int c = p.second + dir[i+1];
                    
                    if( r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == 1  ){
                        grid[r][c] = 2;
                        q.push( { r , c});
                        fresh--;
                    }
                    
                }
                
            }
            ans++;
        }
        
        if(fresh>0) return -1; //if fresh>0 that means there are fresh oranges left
        if(ans==-1) return 0; //we initialised with -1, so if there were no oranges it'd take 0 mins.
        return ans;
    }
};