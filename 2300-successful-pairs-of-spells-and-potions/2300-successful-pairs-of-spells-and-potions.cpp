class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        //  for every spell we will try to find the index at which , its product with potions is larger than success 
        // then for all the indexes in the sorted array , next elements product will be larger too
        // so potions.size() - index will be stored in ans vector
        
        sort(potions.begin(), potions.end());
        vector<int> answer;
        
        int m = potions.size();
        int maxPotion = potions[m - 1];
        
        for (auto& spell : spells) {
            // Minimum value of potion whose product with current spell  
            // will be at least success or more.
            
            long long minPotion = ceil((1.0 * success) / spell);
            
            auto index = lower_bound(potions.begin(), potions.end(), minPotion) - potions.begin();
            answer.push_back(m - index);
        }
        
        return answer;
    }
};