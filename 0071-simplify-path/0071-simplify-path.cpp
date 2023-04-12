class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string> st;
        

        for( int i = 0 ; i < path.size() ; i++){
            
            if( path[i] == '/'){
                continue;
            }
        
            string temp="";
            
            while( i < path.size() && path[i] != '/'){
                temp += path[i];
                i++;
            }
            
            if( temp == "."){
                continue;
            }
            
            if( temp == ".."){
                if( !st.empty()){
                    st.pop();
                }
                continue;
            }
            
            st.push( temp);
            
        }
        
        string result;
        
        while( !st.empty()){
            
            result = "/" + st.top() + result;
            st.pop();
            
        }
        
        if( result.size() == 0){
            return "/";
        }
        
        return result;
    }
};