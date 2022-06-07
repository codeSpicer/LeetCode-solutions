class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        // magical answer using the properties of XOR operation
        // because all the elements except 1 are present twice in the arr
        // we can use xor to cancel out bits of the pair elements and the only solo element will be stored in answer
        
        int ans = 0;
        
        for( auto i : nums){
            ans ^= i;
        }
        return ans;
    }
};