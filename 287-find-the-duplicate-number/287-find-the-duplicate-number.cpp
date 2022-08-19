class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        bool cycle = false;
        
        int slow = 0;
        int fast = 0;
        
        while(!cycle){
            
            slow = nums[slow];
            fast = nums[nums[fast]];
            
            if( slow == fast){
                cycle = true;
            }
        }
        
        slow = 0;
        
        while( slow != fast){
            
            slow = nums[slow];
            fast = nums[fast];
            
        }
        
        return slow;
        
    }
};