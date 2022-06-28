class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        
        int index = ruleKey == "type" ? 0 : ruleKey == "color" ? 1 : 2;
        int counter=0;
        
        for( auto i : items){
            
            if( i[index] == ruleValue ){
                counter++;
            }
            
        }
        
        return counter;
        
    }
};