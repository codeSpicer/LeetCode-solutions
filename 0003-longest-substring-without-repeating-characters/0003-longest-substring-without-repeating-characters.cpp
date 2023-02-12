class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> st;
        
        int l = 0 ; int r = 0;
        int ans = 0;
        
        while( r < s.size() ){
            if( st.count(s[r]) > 0 ){
                while( st.count(s[r]) > 0){
                    st.erase( s[l++]);
                }
            }else{
                st.insert(s[r++]);
            }
            if( st.size() > ans){
                ans = st.size();
            }
        }
        
        return ans;
    }
};