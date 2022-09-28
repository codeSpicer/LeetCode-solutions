class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        
        // pre and post traversal of array to find distance indexes with key char
        
        vector<int> result(s.length() );
        
        // forward pass
        int distance = s.length();
        for( int i = 0 ; i < s.length() ; i++){
            
            if( s[i] == c){
                distance = 0;
                result[i] = distance;
            }else{
                distance++;
                result[i] = distance;
            }
            
        }
        
        // backward pass
        distance = s.length();
        for( int i = s.length()-1 ; i >=0 ; i--){
            
            if( s[i] == c){
                distance = 0;
                result[i] = distance;
            }else{
                distance++;
                // result[i] = distance
                if( distance < result[i]){
                    result[i] = distance;
                }
            }
            
        }
        
        return result;
        
        
    }
};