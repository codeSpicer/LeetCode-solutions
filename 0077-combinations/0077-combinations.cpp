class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> result;
        vector<int> temp;
        
        backtrack( n ,  k , result , temp , 1);
        
        return result;
        
    }
    
    void backtrack( int n , int k , vector<vector<int>> &result , vector<int> temp , int indx ){
        
        if( indx > n+1 ){
            return;
        }
        if( temp.size() == k ){
            result.push_back(temp);
            return;
        }
        
        for(int i = indx ;i<n+1;i++)
        {
            temp.push_back(i);  //consider the current element i
            backtrack( n , k , result , temp , i+1); // generate combinations
            temp.pop_back(); //proceed to next element
        }
        
        
    }
    
};