class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
        
        int i = 0, j = a.size() - 1, k = j;
        
        vector <int> ret(k + 1, 0);         // init vector of nums.size with 0s
        
        while (k >= 0) {
            
            // using 2 pointers, one from the start and one from the end 
            // we iterate towards the 0 in the middle and append the bigger squared number 
            // starting form the end of the returning vector
            
            if (abs(a[i]) > abs(a[j])) ret[k--] = a[i] * a[i++];
            else ret[k--] = a[j] * a[j--];
        }
        
        return ret;
        
    }
};