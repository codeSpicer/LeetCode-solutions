class Solution {
    
/*                                  // THE DFS WAY OF DETECTING CYCLE AND MARKING NODES AS FALSE
private:
    bool detect_cycle( vector<vector<int>> graph , vector<bool>& vis , vector<bool>& path_vis , vector<bool>& safe , int node  ){
        
        vis[node] = true;
        path_vis[node] = true;          // temp visit for dfs to check cycle in path
        
        for( auto neighbour : graph[node]){
            
            if( vis[neighbour] == false ){      // for un visited neighbours 
                if( detect_cycle( graph , vis , path_vis , safe , neighbour )== true ){    // if cycle found we make safe node as false
                    safe[node] = false;         // this marks safe node as false if cycle is found later in path 
                    return true;
                }
            }else if( path_vis[neighbour] == true ){    // or if they are vis but also visited in path that means a cycle is found
                safe[node] = false;             // we make safe node as false 
                return true;
            }
            
        }
        
        path_vis[node] = false;         // un mark visited in temp vis for next dfs call
        safe[node] = true;              // if no cycle is found 
        return false;
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        // the node cannot be a safe state if it is an cycle or later on connects to a cycle 
        // the node can only be a SS if it ends up on a terminal node on all paths
        
        vector<bool> vis(graph.size(),false);
        vector<bool> path_vis( graph.size() , false);
        vector<bool> safeState( graph.size() , false);      // all arrays can be made into one array by using diffrent ints but "readability"
        
        for( int i = 0 ; i < graph.size() ; i++){
            if( vis[i] == false){
                detect_cycle( graph , vis , path_vis , safeState , i ); 
            }
        }
        
        vector<int> safeNodes;
        for( int i = 0 ; i < safeState.size() ; i++){
            if( safeState[i] == true){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
    */
    
                                    // THE TOPOLOGIAL SORT WAY
    
    public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
        
        /* we use topological sort to find eventual states in a graph by reversing the edges
        and performing a topological sort on the reversed graph. 
        The sources in the reversed graph correspond to the eventual states in the original graph.*/
        
        // first we make a reversed adj list because the sources of the topo sort will be the nodes with no out edge
        vector<vector<int>> revAdj( graph.size()); 
        vector<int> inDegree(graph.size() , 0);
        
        for( int i = 0 ; i < graph.size() ; i++){
            for( const auto& edge : graph[i]){
                revAdj[edge].push_back(i);
                inDegree[i]++;
            }
        }
        
        queue<int> q;
        for( int i = 0 ; i < inDegree.size() ;i++){
            if( inDegree[i] == 0){                      // nodes with indegree 0 are the terminal nodes
                q.push( i);
            }
        }
        
        vector<int> res;
        
        // we take the terminal nodes remove their edges and if their neighbour node get to 0 edges then we add it to queue
        // if the neighbour is in a cycle then it will never have 0 indegree
        // and because the graph is reversed , we will never reach nodes which connect to cycles 
        
        while( !q.empty() ){
            
            int node = q.front();
            q.pop();
            
            for( const auto& edge: revAdj[node]){
                inDegree[edge]--;
                if( inDegree[edge] == 0){
                    q.push(edge);
                }
            }
            res.push_back( node);            
        }
        
        sort( res.begin() , res.end());
        
        return res;
        
    }
        
    
};