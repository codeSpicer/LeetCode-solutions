class Solution {
public:
    int kthFactor(int n, int k) {
        
        // vector<int> factors;
        int counter = 0;
        
        for( int i = 1 ; i <= n ; i++ ){
            if( n%i== 0){
                // factors.push_back( i);
                counter++;
            }
            if( counter == k){
                return i;
            }
        }
        return -1;
    }
};