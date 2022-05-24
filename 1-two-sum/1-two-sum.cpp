class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> ans;
        
        unordered_map<int,int> hash;        // first int being the value and second int being the index
        
        for( int i = 0 ;i < nums.size() ; i++){
            
            int complement = target - nums[i];      //complement here is the number to find
            
            if(hash.find(complement) != hash.end()){
                ans.push_back(i);                           // if the complement is present in hashmap
                ans.push_back(hash[complement]);     // put the current index and complements index in ans array
            }
            
            hash.insert({nums[i] , i});             // insert the current number and index to hashmap
        }
        
        return ans;
    }
};