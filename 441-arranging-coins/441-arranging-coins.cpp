class Solution {
public:
    int arrangeCoins(int n) {
        
        int i = 0;
        int coinsInLvl= 1;
        
        while( true){
            
            n -= coinsInLvl;
            if( n >= 0 ){
                coinsInLvl++;
                i++;
            }else{
                return i;
                break;
            }
            
        }
        return 0;
        
    }
};