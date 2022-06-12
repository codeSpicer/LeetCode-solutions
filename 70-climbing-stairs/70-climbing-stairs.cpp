class Solution {
public:
    int climbStairs(int n) {
    
        int one_step = 1;
        int two_step = 2;
        
        if( n==1){
            return 1;
        }
        
        for( int i = 0 ; i < n-2 ;i++){
            
            int temp = two_step;
            two_step += one_step;
            one_step = temp;
            
        }
        
        return two_step;
        
    }
};