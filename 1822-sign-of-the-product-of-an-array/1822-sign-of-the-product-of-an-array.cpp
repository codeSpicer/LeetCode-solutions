class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        int countNegative = 0;
        
        for( const auto& i : nums){
            if( i < 0){
                countNegative++;
            }else if( i == 0 ){
                return 0;
            }
        }
        
        if( countNegative % 2 == 1){
            return -1;
        }
        return 1;
        
    }
};