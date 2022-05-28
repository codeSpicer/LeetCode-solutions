class Solution {
public:
    bool isAnagram(string s, string t) {
        
        
        // similar to leetcode 383 
        // we make 2 arrays to store frequency of values in both stings
        // then we equate all the values of 2 strings to find if they are anagram
        
        
        int arr1[26] = {0};
        int arr2[26] = {0};
        
        for( int i = 0 ; i < s.length() ; i++){
            
            arr1[ int(s[i])-97 ]++;
            
        } 
        
        for( int i = 0 ; i < t.length() ; i++){
            
            arr2[ int(t[i])-97 ]++;
            
        } 
        
        
        for( int i = 0 ;i < 26 ; i++){
            
            if( arr1[i]  != arr2[i]){
                return false;
            }
            
        }
        
        return true;
        
    }
};