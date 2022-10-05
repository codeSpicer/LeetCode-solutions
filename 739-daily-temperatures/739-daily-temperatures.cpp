class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        // instead of using elements in monotonic stack we can use index of elements and compare wtih elements 
        
        stack<int> st;
        vector<int> result(temperatures.size());
        
        for( int i = 0 ; i < temperatures.size() ; i++){
            
            while( !st.empty() && temperatures[st.top()] < temperatures[i]){
                result[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
            
        }
        
        return result;
        
    }
};