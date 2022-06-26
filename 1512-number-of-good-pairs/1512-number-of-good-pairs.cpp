class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        // step 1) check constraints
        // we dont really need the index of the values we just need count of values
        // a hashmap or an array of size 100 can be used to store values
        
        unordered_map< int , int > mp ;    // first one is value and second is its count
        
        int ans=0;
        
        for( auto n: nums){
            ans += mp[n]++;     // works like n*(n+1)/2 
        }
        
        return ans;
        
    }
};