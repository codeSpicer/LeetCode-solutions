class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> result( n+1);
        
        
        for( int i = 0 ; i <= n ;i++){
            
            int bits = 0;
            int num = i;
            
            while( num >0 ){
                
                bits += num&1;
                num>>=1;
                
            }
            
            result[i] = bits;
            
        }
        
        
        return result;
    }
};