class Solution {
public:
    string makeGood(string s) {
        
        stack<char> st;
        
        for( int i = 0 ; i < s.length() ; i++){
            if( !st.empty() && ( st.top() == char( s[i]+32) || st.top() == char( s[i]-32 ))){
                st.pop();
                // cout<< "poping "<< s[i]<< " ";
            }else{
                st.push(s[i]);
                // cout<< s[i]<<" ";
            }
        }
        
        string temp = "";
        
        while( !st.empty() ){
            char c = st.top();
            st.pop();
            temp = c + temp;
        }
        
        return temp;
    }
};