class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int right = letters.size()-1;
        
        if( target >= letters[right]){
            return letters[0];
        }
        
        // idea is to use binary search and move towards the right 
        // of target element for test cases like [ a a a a a a b c]
        
        int left=0;
        
        while ( left <= right){
            
            int mid = (left + right)/2;
            
            if( letters[mid] <= target){
                left = mid+1;
            }else{
                right = mid-1;
            }
            
        }
        
        return letters[left];
        
    }
};