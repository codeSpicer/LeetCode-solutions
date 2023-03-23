class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        // first we make a bool array of visited and then we traverse that array we perform bfs or dfs on every unvisited node
        // while doing bfs we mark every node connected to it as visited and increment provinces counter by one
        
        int provinces = 0;
        vector<bool> visited(isConnected.size() , false);
        
        
        for( int i = 0 ; i < visited.size() ; i++){
            
            if( !visited[i] ){
                provinces += 1;
                dfs( isConnected , visited , i );
            }
            
        }
        return provinces;
    }
    
    void dfs( vector<vector<int>> g , vector<bool> &visited , int node ){
    
        visited[node]=true;
        
        for( int i = 0 ; i < g.size() ; i++){
            if( g[node][i] == 1 && !visited[i]){
                dfs( g , visited , i);
            }
        }
        
    }
    
    
};