class Solution {
public:
    string reverseWords(string s) {
        
        string res="";
        int left = 0;
        int right = s.length()-1;
        
        while( s[left] == ' ') left++;
        while( s[right] == ' ') right--;    // removing white spaces
        
        // now we can iterate words from back side and add them to result string
        int i = right;
        while( i >= left){
            
            int count= i;
            int temp=0;
            while( count >= left && s[count] != ' '){ 
                count--;
                temp++;
            }// after this count will be at start of word
            
            res+= s.substr( count+1 , temp);
            if( count>left){
                res+=' ';
            }
             
            while(count>=left &&  s[count]==' '){
                count--;
            }
            i=count;
            
        }
        
        return res;
        
    }
};