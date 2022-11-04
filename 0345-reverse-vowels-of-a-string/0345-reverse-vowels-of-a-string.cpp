class Solution {
public:
    
    bool isVowel(char c) {
        return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u'
            || c == 'A' || c == 'I' || c == 'E' || c == 'O' || c == 'U';
    }
    
    string reverseVowels(string s) {
        
        char vowels[] = { 'a' , 'e' , 'i' , 'o' , 'u' ,'A' , 'E' , 'I' , 'O' , 'U'};
        
        int i = 0 ;
        int j = s.length()-1;
        
        while( i < j ){
            
            while( i < s.size() && !isVowel(s[i])){
                i++;
            }
            while( j >= 0 && !isVowel(s[j])){
                j--;
            }
            if( i < j){
                swap( s[i++] , s[j--]);
            }
        }
        
        return s;
    }
    
};