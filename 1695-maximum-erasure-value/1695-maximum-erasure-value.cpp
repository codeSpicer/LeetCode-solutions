class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        // my approach would be to make a set to store distinct elements for the array 
        // and maintain to pointers , the right pointer would iterate and store element not in set
        // if we encounter an element in set we move the left pointer forward and pop elements out of the set
        // also to maintain a current sum and max sum 
        // while inserting and poping elements out of set we will add and subs from the current sum likewise
        
        unordered_set<int> s;
        int max_sum = 0;
        int cur_sum = 0;
        
        int left , right = 0;
        
        while( right < nums.size()){
            
            if( s.find(nums[right]) == s.end()){
                s.insert(nums[right]);
                cur_sum += nums[right];
                right++;
            }else{
                s.erase(nums[left]);
                cur_sum -= nums[left];
                left++;
            }
            max_sum = max( max_sum , cur_sum);
            
        }
        return max_sum;   
    }
};