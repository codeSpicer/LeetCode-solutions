//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    
    void dfs( vector<int> adj[] , vector<int> &res  , vector<bool> &vis, int node){
        vis[node] = true;
        
        for( auto i : adj[node]){
            if( !vis[i]){
                dfs( adj , res , vis , i );
            }
        }
        
        res.push_back( node);
        
    }   
    
    
    
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    /*
	    vector<bool> visited( V , false);
	    vector<int> res;
	    
	    for( int i = 0 ; i < V ; i++){
	        if( !visited[i]){
	            dfs( adj , res , visited , i);   
	        }
	    }
	    reverse( res.begin() , res.end());
	    return res;
	    */
	    
	    // khans algorithm
	    
	    vector<int> inDegree( V , 0);   // in degree of every node
	    queue<int> q;
	    vector<int> result;
	    
	    for( int i = 0 ; i < V ; i++){
	        for( auto x : adj[i]){
	            inDegree[x]++;
	        }
	    }
	    
	    for( int i = 0 ; i < V ; i++){
	        if( inDegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    while( !q.empty()){
	        int node = q.front();
	        q.pop();
	        
	        for( auto i : adj[node]){
	            inDegree[i]--;
	            if( inDegree[i] == 0){
	                q.push(i);
	            }
	        }
	        result.push_back(node);
	        
	    }
	    
        return result;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends