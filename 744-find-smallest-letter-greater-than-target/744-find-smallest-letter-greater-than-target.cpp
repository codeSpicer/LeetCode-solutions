class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int n = letters.size()-1;
        
        if( letters[n] <= target){
            return letters[0];
        }
        
        int i = 0;
        
        while( i < n ){
            
            int mid = (i+n)/2;
            
            if( target < letters[mid]){
                n= mid;
            }else{
                i = mid+1;
            }
        }
        
        return letters[i];
        
    }
};