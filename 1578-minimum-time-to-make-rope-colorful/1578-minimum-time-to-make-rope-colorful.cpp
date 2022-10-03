class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int result =0;
        
        for( int i = 0 ; i < colors.length()-1 ; i++){
            
            int Max= INT_MIN;
            int cur_sum  = 0;
            while( colors[i] == colors[i+1]){
                cur_sum += neededTime[i];
                Max = max( Max , neededTime[i]);
                i++;
            }
            cur_sum += neededTime[i];
            Max = max( Max , neededTime[i]);
            
            result += cur_sum - Max;
            
        }
        
        return result;
    }
};