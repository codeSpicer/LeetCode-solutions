class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // https://www.youtube.com/watch?v=3IETreEybaA
        
        // basic idea we use a set and iterate our right ptr and add elements in the set
        // when we see a already added element then we start moving the left ptr and remove the elements         //from the set
        // it goes on till the element we encounterd on the right ptr isnt removed
        // once its gone we continue moving out right ptr
        
        unordered_set<int> uset ;
        
        int left=0;
        int right = 0;
        int max_subs = 0;
        
        while( right < s.length() ){
            
            if( uset.find(s[right]) == uset.end()){
                uset.insert( s[right] );
                max_subs = max( max_subs , int(uset.size()) );
                right++;
            }else{
                uset.erase( s[left]);
                left++;
            }
            
        }
        
        return max_subs;
        
    }
};