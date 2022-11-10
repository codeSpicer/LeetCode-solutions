class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        stack<char> st;
        
        int n = s.length();
        for(int i=0;i<n;i++){
            if(!st.empty() && st.top()==s[i]){
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        
        while(!st.empty()){
            ans = st.top()+ans;
            st.pop();
        }
        
        return ans;
    }
};