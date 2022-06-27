class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        // o(n) o(n) sol is we add all elements to set and check for values from 1 to n+k+1 when counter == k we return i of for loop
        
        
        unordered_set<int> st;
        int count = k;
        
        for( int i = 0 ;i < arr.size() ; i++){
            st.insert(arr[i]);
        }
        
        for( int i = 1 ; i < arr.size() + k+1 ; i++){
            if( st.find(i) == st.end()){
                --count;
            }
            if( count == 0){
                return i;
            }
        }
        
        
        return -1;
    }
};