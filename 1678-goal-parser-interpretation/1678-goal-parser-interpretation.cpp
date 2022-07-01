class Solution {
public:
    string interpret(string str) {
        
        string res ;
        
        for(int i = 0 ;i < str.length() ; i++){
            
            if( str[i] == 'G' ){
                res += "G";
            }else if( str[i+1] == ')'){
                res+= 'o';
                i+=1;
            }else{
                res += "al";
                i+=3;
            }
        }
        
        return res;
        
    }
};