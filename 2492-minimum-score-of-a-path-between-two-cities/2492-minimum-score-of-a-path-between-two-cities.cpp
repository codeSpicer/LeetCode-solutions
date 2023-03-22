class Solution {
public:
    
    
    int minScore(int n, vector<vector<int>>& roads) {
        // first we make a adj list then use bfs to find min score
        vector<vector<pair<int,int>>> g(n+1);        // pre define space needed when ever not pushing elements in vector !!
        // for every node we store a places it can visit and distance to visit that place
        
        for( const auto &road : roads){
            g[road[0]].push_back( {road[1] , road[2]});     // we add destination and distance in the current nodes vector
            g[road[1]].push_back( { road[0] , road[2]});    // same from the other side because non directional
        }
        
        // now we have graph made , we do bfs 
        
        int result = INT_MAX;
        
        vector<bool> visited(n+1);  // +1 because no 0th node
        queue<int> q;
        q.push(1);
        visited[1]= true;
        
        while( !q.empty() ){
            
            
            int current = q.front();
            q.pop();
            
            for( const auto& edge : g[current]){            // for every edge going out from current city
                
                result = min( result , edge.second);    // we update our path if any new smaller path is found
                
                if( !visited[edge.first]){
                    q.push(edge.first);
                    visited[edge.first] = true;
                }
                
            }
            
        }
        
        return result;
        
    }
};