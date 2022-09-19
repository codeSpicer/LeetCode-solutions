class Solution {
public:
        int minimumOperations(vector<int>& A) {
        unordered_set<int> s(A.begin(), A.end());
        
        for( auto i : s){
            cout<< i <<" ";
        }
        
        return s.size() - s.count(0) ;
            
    }
};