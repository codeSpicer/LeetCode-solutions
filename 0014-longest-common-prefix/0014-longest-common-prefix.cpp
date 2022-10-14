class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if( strs.size() == 0){
            return "";
        }
        
        for( int i = 0 ; i < strs[0].size() ; i++){     // outer for loop till length of first word
            // because result cannot be longer than smallest word in the array so we take any word
            
            for( int j = 1 ; j < strs.size() ; j++){
                // for every charater in that word we check if all the words in the string vector
                // have same charater in same index
                
                // if we find some word has length equal to current index in first word or 
                // some char in some word is not same then we
                // return sub str of any word from 0 to cur index
                if( i == strs[j].size() || strs[j][i] != strs[0][i] ){
                    return strs[0].substr(0 , i);
                }
                
            }
            
        }
        // if all strings are same or only one string then above condition wont execute ever
        return strs[0];
        
    }
};