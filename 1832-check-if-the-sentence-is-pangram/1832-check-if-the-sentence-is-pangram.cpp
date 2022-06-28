class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        // initial idea o( n)
        // space constant
        
        // make an array of 26 for bool present and make a counter
        // for every char if it appeared for first time we increment the counter 
        // once counter hits 26 we return true else false
        
        vector<bool> present(26);
        int counter = 0;
        
        for( int i = 0 ; i < sentence.length() ; i++){
            if( present[ sentence[i] - 'a'] == 0){
                counter++;
                present[sentence[i]-'a'] = 1;
            }
            if( counter == 26){
                return true;
            }
        }
        return false;
        
    }
};  