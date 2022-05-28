class Solution {
public:
    int firstUniqChar(string s) {
        
        // general idea add everyting in a onordered map 
        // then loop the array to find first element with freq 1
        // return it
        // time complexity O(n) space complexi o(1) because there are only 26 characters
        
        
        unordered_map<int,int> mp ;
        
        for( int i = 0 ; i < s.length() ; i++){
            mp[s[i]]++;
        }
        
        int index = -1;
        
        for( int i = 0 ;i < s.length() ; i++){
            if(mp[s[i]]==1){
                return i;
            }
        }
        
        return index;
        
    }
};