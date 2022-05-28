class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int ransom[26] = {0};
        int mag[26] = {0};
        
        for( int i = 0 ; i < ransomNote.length() ; i++){
            
            ransom[ int(ransomNote[i])-97 ]++;
            
        } 
        
        for( int i = 0 ; i < magazine.length() ; i++){
            
            mag[ int(magazine[i])-97 ]++;
            
        } 
        
        
        for( int i = 0 ;i < 26 ; i++){
            
            if( mag[i]  < ransom[i]){
                return false;
            }
            
        }
        
        return true;
    }
};