class Solution {
public:
    string decodeString(string s) {
        
        stack<char> st;
        int n = s.length() ;
        
        for( int i = 0 ; i < n ; i++){
            
            if( s[i] != ']'){
                st.push( s[i]);
            }else{
                
                string temp = "";
                while( st.top() != '['){
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();   // for '['
                string number = "";
                
                while(!st.empty() && isdigit(st.top())  ){
                    number =  st.top() + number;
                    st.pop();
                }
                
                int multiple = stoi( number);
                
                while( multiple-- ){
                    for( int j = 0 ; j < temp.size() ; j++){
                        st.push( temp[j]);
                    }
                }
                
            }
            
        }
        
        string result = "";
        while( !st.empty()){
            result = st.top() + result;
            st.pop();
        }
        return result;
       
    }
};