class Solution {
public:
    int maxVowels(string s, int k) {
        
        unordered_set<char> st = { 'a' , 'e' , 'i' , 'o' , 'u'};
        
        int i = 0 ; int j = k ;
        int max = 0;
        int temp = 0;
        for( int i = 0 ; i < k ; i++){
            if( st.find(s[i]) != st.end() ){
                temp++;
                if( temp > max ){
                    max = temp;
                }
            }
        }
        
        while( j < s.size() ){
            if( st.find(s[i]) != st.end() ){
                temp--;
            }
            if( st.find( s[j]) != st.end()){
                temp++;
            }
            i++; j++;
            if( temp > max){
                max = temp;
            }
        }
        return max;
    }
};