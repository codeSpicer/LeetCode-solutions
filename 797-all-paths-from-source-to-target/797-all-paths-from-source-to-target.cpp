class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        vector<vector<int>> result;
        path.push_back(0);
        
        dfs( result , path , graph , 0);
        
        return result;
    }
    
    void dfs( vector<vector<int>> &result , vector<int> &path , vector<vector<int>>& graph , int index ){
        
        if( path[path.size() -1] == graph.size()-1){
            result.push_back( path);
        }
        
        for( const auto& i : graph[index]){
            path.push_back(i);
            dfs( result , path , graph , i);
            path.pop_back();
        }
        
        
    }
};