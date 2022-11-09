class Solution {
public:
    vector<int> original;
    
    Solution(vector<int>& nums) {
        original = nums;            // storing the initial array in global variable
    }
    
    vector<int> reset() {
        return original;            // returns original stored array
    }
    
    vector<int> shuffle() {
        vector<int> array = original;   // makes an copy of original array 
        
        for( int i = 0 ; i < array.size() ; i++){  // swaps all indexs with random indexes
            swap( array[i] , array[ rand()%array.size() ]); 
        }
        return array;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */