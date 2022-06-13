class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // one approach is to make a hashmap to store frequencies of all elements
        // then start adding them to k size heap
        // poll elements from the heap and add them to result vector
        
        // second approach is to make a hashmap and store freq
        // start adding them to bucket sort with frequency as key and element as item
        // iterate the buckets from the left side and add items to result array
        
        unordered_map<int,int> map;     // value , frequency
        vector<int> result;
        
        for( auto &n : nums){
            map[n]++;           // mapping frequencies
        }
        
        vector<vector<int>> bucket( nums.size()+1);     // +1 so for cases like [1,1,1,1]
        
        for( auto [val , freq] : map ){
            bucket[freq].push_back(val);         // assigning values to frequencies
        }
        
        for( int i = nums.size() ; i >= 0 && result.size() <k ;i--){
            for(int num :bucket[i]){
                result.push_back(num);    // then add value to res
                if(result.size()==k){
                    break;      //once k elements are added break the loop
                }                
            }
            
        }
        
        return result;
        
        
    }
};