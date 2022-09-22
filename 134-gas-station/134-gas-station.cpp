class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        // we can only go a circle if we have more total gas than cost
        int total=0;
        for( int i = 0 ; i < gas.size() ; i++){
            total += gas[i] - cost[i];
        }
        if( total < 0){
            return -1;
        }
        
        // the starting point must come after 1 or more stations where cost is more than gas
        
        int ans =0; total = 0;
        
        for( int i = 0 ; i < gas.size() ; i++){
            
            total += gas[i] - cost[i];
            if( total < 0){
                total = 0;
                ans = i+1;
            }
            
        }
        
        return ans;
        
    }
};