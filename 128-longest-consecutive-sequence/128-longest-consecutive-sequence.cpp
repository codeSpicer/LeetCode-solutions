class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        // idea is to add all the elements in nums to a set
        // then loop nums again and try find if current numbers previous num is in the set
        // if not present for ith element then we start counting the max elements from there 
        // update max if greater than prev max
        
        // time comp -> O(2N)
        // space cmp -> O(N);
        
        unordered_set<int> set;
        int Max=0;
        int temp_max=0;
        
        for( auto &n : nums ){
            set.insert(n);
        }
        
        for( auto &n : nums){
            
            if( !set.count(n-1)){
                // element is first in this sequence
                int num = n;
                temp_max++;
                while( set.count(++num)){   // while next element in sequence is present
                    temp_max++;
                }
                Max = max( temp_max , Max);
                temp_max=0;
                
            }
            
        }
        return Max;
    }
};