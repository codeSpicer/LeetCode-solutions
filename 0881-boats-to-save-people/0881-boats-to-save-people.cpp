class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        // we can sort the people then use two pointer approach
        // if last + first > limit , we assign 1 boat to last person and move last to last-1
        // if last + first <= limit we move both pointers and assign 1 boat to each
        sort( people.begin() , people.end());
        
        int low = 0 ;
        int high = people.size()-1;
        int ans = 0;
        while( low <= high){
            
            if( people[low] + people[high] > limit){
                ans++;
                high--;
            }else{
                low++;
                high--;
                ans++;
            }
            
        }
        
        return ans;
        
    }
};