class Solution {
public:
    void reverseString(vector<char>& s) {
        
        // 2 pointers 
        // one at start one at end going towards each other 
        // swapping their elements
        
        int i = 0;
        int j = s.size()-1;
        
        while( i < j ){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++; j--;
        }
        
    }
};