class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> st;
        
        int pop = 0;
        
        for( const auto &i : pushed){
            
            st.push(i);
            
            while( !st.empty() && popped[pop] == st.top() ){
                st.pop();
                pop++;
            }
            
        }
        
        return st.empty() && pop == popped.size();
        
    }
};