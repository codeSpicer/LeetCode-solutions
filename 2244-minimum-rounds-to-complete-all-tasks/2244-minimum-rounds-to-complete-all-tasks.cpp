class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        unordered_map<int,int> freq;
        
        for( const auto &i : tasks ){
            freq[i]++;
        }
        
        int result=0;
        
        for( auto [first,second] : freq){
            
            if( second == 1 ){
                return -1;
            }
            if( second % 3 == 0){
                result += second/3;
            }else{
                result += second/3 + 1;
            }
        }
        return result;
    }
};