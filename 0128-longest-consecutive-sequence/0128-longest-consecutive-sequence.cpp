class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int > mp( nums.begin() ,  nums.end() );
        
        int maxConsec=0;
        for( int i = 0 ; i < nums.size() ; i++){
            if( mp.find( nums[i]-1) == mp.end() ){
                int temp= 1;
                int num = nums[i];
                while( mp.find( num+1) != mp.end() ){
                    temp++;
                    num++;
                }
                maxConsec = max( maxConsec , temp);
            }
        }
        
        return maxConsec;
        
    }
};