class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        // can be done by sorting the array in nlogn time and const extra memory
        
        // or can be done by using a *set* and return the s.end()-3 element , which is n time but n space
        
        // it can also be done via n time and const space by not letting set exceed 3 elements and always delete set.begin when we put new element in the set 
        // at last return set.begin 
        
        set<int> s;
        
        for( auto n : nums){
            
            s.insert(n);
            if( s.size() > 3){
                s.erase(s.begin());
            }
            
        }
        
        if( s.size() == 3){
            return *s.begin();      // remember the pointer needs to be dereferenced
        }
        
        return *s.rbegin();
        
    }
};