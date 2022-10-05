class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        unordered_map<int , int> m;
        
        m[edges[0][0]]++;
        m[edges[0][1]]++;
        m[edges[1][0]]++;
        m[edges[1][1]]++;
        
        if( m[edges[0][0]] == 2){
            return edges[0][0];
        }
        
        return edges[0][1];
        
    }
};