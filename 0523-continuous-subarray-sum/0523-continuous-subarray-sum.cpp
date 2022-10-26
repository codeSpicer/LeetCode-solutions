class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        // brute force would be to make 2 for loops try out all the sub array and check if multiple of k
        
        // the working solution uses a hashmap to store the remainders we have already seen as keys and the index they were seen at as values;
        
        //when we encounter the same remainder again that means from the last time we saw that remainder
        // till the current index the sum of subarray's remainder is 0 
        // to check if it is greater than 1 length we are using indexes as value and check is cur_val - prev_val >= 1
        
        unordered_map<int, int> mp = {{0, -1}};   // add a 0 index value if in case the first num is divisible by k 
        
        int runningSum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            runningSum+=nums[i];
            
            if(k!=0) 
                runningSum = runningSum%k;
            
            //check if the runningsum already exists in the hashmap
            if(mp.find(runningSum)!=mp.end())
            {
                //if it exists, then the current location minus the previous location must be greater than1
                if(i-mp[runningSum]>1)
                    return true;
            }
            else
            {
                //otherwise if the current runningSum doesn't exist in the hashmap, then store it as it maybe used later on
                mp[runningSum]=i;
            }
                    
        }
        return false;
    }
    
};