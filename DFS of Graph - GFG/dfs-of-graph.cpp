//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> result;
        vector<bool> visited( V , false);
        
        dfs( adj , visited , result , 0);
        
        return result;
    }
    
    void dfs( vector<int> adj[] , vector<bool> &visited , vector<int> &result , int cur){
        
        if( visited[cur] ){
            return;
        }
        
        visited[cur] = true;
        result.push_back( cur);
        
        for( auto neighbour : adj[cur]){
            dfs( adj , visited , result , neighbour);
        }
        
    }
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends