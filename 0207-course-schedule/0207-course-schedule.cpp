class Solution {
private:    
    
//     bool detectCycle( int node , int parent , vector<int> adj[] , vector<bool> &visited ){
        
//         visited[node] = true;
        
//         for( const auto& neighbour : adj[node]){
            
//             if( !visited[neighbour] ){
//                 if( detectCycle(neighbour , node , adj , visited) == true ){
//                     return true;
//                 }
//             }else if( neighbour != parent ){
//                 return true;
//             }
//         }
//         return false;
//     }
    
public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
//         vector<int> adj[numCourses];    // adj list of course
        
//         for( const auto& edge : prerequisites){
//             adj[edge[1]].push_back(edge[0]);
//         }
        
//         vector<bool> visited(numCourses , false);
        
//         for( int i = 0 ; i < numCourses ; i++){
//             if( detectCycle( ))
//         }
        
//     }
    
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        for(auto edge : pre)
            adj[edge[1]].push_back(edge[0]);
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++){
            if(iscycle(adj,vis,i))
                return false;
        }
        return true;
    }
    
    bool iscycle(vector<int> adj[],vector<int> &vis,int id){
        if(vis[id]==1)
            return true;
        if(vis[id]==0){
            vis[id]=1;
            for(auto edge : adj[id]){
                if(iscycle(adj,vis,edge))
                    return true;
            }
        }
        vis[id] = 2;
        return false;
    }
};