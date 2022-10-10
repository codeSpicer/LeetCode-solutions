class Solution {
public:
    string breakPalindrome(string s) {
        
        if( s.length() == 0 || s.length() == 1){
            return "";      // for len 0 & 1 there can be no lexico smaller string
        }// a , b , z
            
        // for a string of same characters 
        // if all characters are aaaa then we need to make the last char  b
        // else if it is anything other than a like bbbbbbbbbb then we can make the first char a
        // 
            
            
            // aa , aaaaaaaaaaa
            // aabaa  , aza , 
        bool OnlyA = true;
        bool OnlyOneNonA = true;
        int nonA = 0;
        for( int i = 0 ; i < s.length() ; i++){
            if( s[i] != 'a'){
                nonA++;
                OnlyA = false;
                if( nonA > 1){
                    OnlyOneNonA = false;
                    break;
                }
            }
        }
        
        // problem test case 
        // aaaabaaaa
        
        if( OnlyA || OnlyOneNonA){
            s[s.length()-1]= 'b';
            return s;
        }
        
        for( int i = 0 ; i < s.length() ; i++){
            if( s[i] != 'a' ){
                s[i] = 'a';
                break;
            }
        }
        
        return s;
        
    }
};