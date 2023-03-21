class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        long long count = 0;
        
        long long result = 0;
        
        // number of sub arrays in a array is  -> (n * (n+1)) / 2 
        
        for( const auto &i : nums){
            if( i == 0 ){
                count++;
            }else{
                result = result + ( count * (count+1) ) /2;
                count = 0;
            }
        }
        if( count != 0 ){
            result = result + ( count * (count+1) ) /2;
        }
        
        return result;
        
    }
};