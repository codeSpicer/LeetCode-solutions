class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        
        // we can do a modified quick sort for parity
        // also we can do the basic make a new array and 2 pass to store even then odd
        
        // but we can do a inplace o(n) 2 pointer solution , by swapping the indexes 
        
        for (int i = 0, j = 0; j < A.size(); j++)
            if (A[j] % 2 == 0){
                swap(A[i++], A[j]);
            } 
        return A;
        
    }
};