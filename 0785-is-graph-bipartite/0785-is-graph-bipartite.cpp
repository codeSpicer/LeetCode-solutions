class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int> color( graph.size() , -1);
        
        // -1 represents unvisited in graph , 0 represents first color , 1 represents second color
        
        for( int i = 0 ; i < graph.size() ; i++){               // for loop to run through unvisited nodes in case of un connected components
            if( color[i] == -1){
                if( dfs( graph , color , i , 0) == false ){     // setting initial nodes color as 0 
                    return false;
                }
            }
        }
        
        return true;
        
    }
    
    bool dfs( vector<vector<int>> graph , vector<int> &color , int node , int col){
        
        color[node] = col;      
        
        for( const auto& neighbour : graph[node]){      // loops through every neighbour
            if( color[neighbour] == -1){                // if neighbour is unviisted it calls the dfs function and colours it the opposite color
                if( dfs( graph , color , neighbour , 1-col ) == false){
                    return false;                       // to return false if some node in graph is not bipartite
                }
            }else if( color[neighbour] == col){         // if the node was already visited but has same color as the current node then it is not bipartite graph and we return false
                return false;
            }   
        }
        return true;
        
    }
    
};