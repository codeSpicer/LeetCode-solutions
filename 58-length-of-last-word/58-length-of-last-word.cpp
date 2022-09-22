class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int n = s.length()-1;
        
        int counter = 0;
        
        while( n >= 0 && s[n] == ' '){
            n--;
        }
        
        while(n >= 0 && s[n] != ' '){
            counter ++;
            n--;
        }
        return counter;
    }
};