class Solution {
public:
    int addDigits(int num) {
        
        int res=0;
        
        while( num > 0){
            
            res += num%10;
            num /= 10;
            
            if( res > 9){
                int temp = res%10;
                res /=10;
                res+=temp;
            }
            
        }
        
        return res;
        
    }
};