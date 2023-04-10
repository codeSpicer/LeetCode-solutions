class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        
        for( const auto &ch : s){
            
            if( ch == '(' || ch == '{' || ch == '['){
                st.push( ch);
            }else{
                
                if( st.empty() || ( ch == ')' && st.top() != '(' ) || ( ch == ']' && st.top() != '[' ) || ( ch == '}' && st.top() != '{' ) ){
                    return false;       // if the closing bracket does not match the top bracket then it will never pop and parentheses are not valid
                }
                st.pop();
            }
            
        }
        return st.empty();  // in case of only opening pairs
    }
};