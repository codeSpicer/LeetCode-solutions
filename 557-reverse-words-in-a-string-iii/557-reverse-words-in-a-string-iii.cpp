class Solution {
public:
    

    string reverseWords(string s) {

        int l, r = 0;
        int len = s.size();
        
        while( l < len){
            
            while( r < len && s[r] != ' '){
                r++;
                
                
            }
            
            reverse( s.begin()+l , s.begin()+r);
            l = r+1;
            r= l;
        }
        
        return s;
        
    }
};