/*
class Solution {
private:
    
bool bfs(vector<vector<pair<int,int>>> adj, int start, int end, int limit) {
    queue<int> q;
    q.push(start);
    vector<bool> visited(adj.size(), false);
    visited[start] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (node == end) {
            return true;
        }
        for (int i = 0; i < adj[node].size(); i++) {
            if (adj[node][i].second < limit && !visited[adj[node][i].first]) {
                q.push(adj[node][i].first);
                visited[adj[node][i].first] = true;
            }
        }
    }
    return false;
}

    
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        // will make a adj list of the graph and use the smallest dis if there are multiple dis
        // then do a bfs for each query to find if i can reach the other node with given restrictions
        
        vector<vector<pair<int,int>>> adj(n);
        
        for( const auto& edge : edgeList){
            
            adj[edge[0]].push_back( {edge[1] , edge[2]});
            adj[edge[1]].push_back( {edge[0] , edge[2]});
            
        }
        
        vector<bool> answer( queries.size());
        
        for( int i = 0 ; i < queries.size() ; i++){
            
            answer[i] = bfs( adj , queries[i][0] , queries[i][1] , queries[i][2] );
            
        }
        return answer;
    }
};
*/      // runs 12 /23 test cases and then time limit exceeded for others

class DSU {
    public:
    vector<int> Parent, Rank;
    DSU(int n) {
        Parent.resize(n);
        Rank.resize(n, 0);
        for (int i = 0; i < n; i++) Parent[i] = i;
    }
    int Find(int x) {
        return Parent[x] = Parent[x] == x ? x : Find(Parent[x]);
    }
    bool Union(int x, int y) {
        int xset = Find(x), yset = Find(y);
        if (xset != yset) {
            Rank[xset] < Rank[yset] ? Parent[xset] = yset : Parent[yset] = xset;
            Rank[xset] += Rank[xset] == Rank[yset];
            return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DSU dsu(n);
        for(int i=0;i<queries.size();i++)
            queries[i].push_back(i);
        
        sort(queries.begin(), queries.end(), [&](auto const &a, auto const &b){
            return a[2] < b[2];
        });
        sort(edgeList.begin(), edgeList.end(), [&](auto const &a, auto const &b){
            return a[2] < b[2];
        });
        
        int i=0;
        vector<bool> res(queries.size(), false);
        for(auto q: queries){
            while(i<edgeList.size() && edgeList[i][2]<q[2]){
                dsu.Union(edgeList[i][0] , edgeList[i][1]);
                i++;
            }
            
            if(dsu.Find(q[0]) == dsu.Find(q[1]))
                res[q[3]] = true;
        }
        
        return res;
    }
};