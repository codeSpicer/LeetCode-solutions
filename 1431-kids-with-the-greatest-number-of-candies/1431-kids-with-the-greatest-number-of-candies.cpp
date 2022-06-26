class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        // first find out max candies 
        // second pre compute the amount of candies needed to have max candies with extras 
        // == maxCandies - extracandies
        
        // precomputing helps us not do extra operations at every step
        
        int maxCandies = 0;
        for( auto candy : candies){
            maxCandies = max( candy , maxCandies);
        }
        
        int candiesBenchmark = maxCandies - extraCandies;
        
        vector<bool> ans ;
        
        for( auto candy : candies){
            if( candy >= candiesBenchmark ){
                ans.push_back(1);
            }else{
                ans.push_back(0);
            }
        }
        
        
        return ans;
        
    }
};