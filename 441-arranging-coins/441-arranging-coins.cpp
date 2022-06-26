class Solution {
public:
    int arrangeCoins(int n) {
        
    // this can be done in logn time using binary search 
        // using a formula used to calculate sum of natural numbers
    // n would be equal to rows in this case n(n+1)/2
        
        int low = 1; 
        int high = n;
        int ans =0;
        
        while( low <= high){
            
            long long mid = low + ( high - low)/2;
            
            long long coins = mid* ( mid +1 )/2;
            
            if( n == coins){
                return mid;
            }
            
            if( coins > n){
                high = mid-1;
            }else if( coins < n ){
                low = mid+1;
            }
            
        }
       
        return high;
    }
};