class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
//         stack<int> st;
        
//         int pop = 0;
        
//         for( const auto &i : pushed){
            
//             st.push(i);
            
//             while( !st.empty() && popped[pop] == st.top() ){
//                 st.pop();
//                 pop++;
//             }
            
//         }
        
//         return st.empty();
        
        // it can be done in o(1) space if we use the pushed array as a stack while maintaing a pointer
        
        int i = 0 ;
        int j = 0 ;
        
        for( auto x : pushed ){
            
            pushed[i++] = x ;
            
            while( i>0 && pushed[i-1] == popped[j]){
                j++;
                i--;
            }            
        }
        
        return i==0 ;
        
    }
};