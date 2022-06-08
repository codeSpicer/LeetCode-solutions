class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // first we sort the array 
        // then we lock an element then apply the logic of 2sum on the remaining array 
        // so left and right pointers to find if we can add up to zero
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        
        for (unsigned int i=0; i<nums.size(); i++) {
            if ((i>0) && (nums[i]==nums[i-1])){     // if i is >0 there is no way total will be less then 0
                continue;                           // in a sorted array
        }
        
            int l = i+1, r = nums.size()-1;         // l and r pointers to find other 2 numbers
            
            while (l<r) {
                int s = nums[i]+nums[l]+nums[r];
                if (s>0) r--;
                else if (s<0) l++;                  // 2 sum logic
                else {
                    res.push_back(vector<int> {nums[i], nums[l], nums[r]});     // directly pushing vector
                    while (l<r &&nums[l]==nums[l+1]) l++;
                    while (l<r && nums[r]==nums[r-1]) r--;         // we move the index forward if the elements are same to avoid duplicate triplets ... we can also use set but this is more memory efficient
                    l++; r--;
                }
            }
        }
        return res;

        
        
    }
};