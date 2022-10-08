class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        unordered_set<int> s;
        for( int i = 0 ; i < n ;i++){
            s.insert( i);
        }
        
        for(const auto& i : edges){
            s.erase(i[1]);
        }
        
        vector<int> result;
        
        for(const auto& i : s ){
            result.push_back(i);
        }
        
        return result;
    }
};