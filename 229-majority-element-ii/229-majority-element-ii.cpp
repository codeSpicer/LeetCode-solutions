class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        // store freqs of elements in a hashmap and if frequency goes above n/3 we add it to the ans
        
        int n = nums.size();
        
        vector<int> arr;
        
        unordered_map<int,int> map;
        
        for( int i = 0 ;i < n ; i++){
            
            if(++map[nums[i]] > n/3){       // increment freq and checks cond.
                arr.push_back(nums[i]);
                map[nums[i]] = -n;    // once added to nums[i] we dont want it to get added to ans again
            } 
            
        }
        return arr;
    }
};