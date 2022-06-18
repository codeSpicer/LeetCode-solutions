class Solution {
public:
    vector<int> countBits(int n) {
        
        if( n < 1){
            return vector<int>{0};
        }
        vector<int> result( n+1);
        result[0]=0;
        result[1]= 1;
        
        for( int i = 2 ;i < n+1 ;i++){

            result[i] = result[i/2] + (i%2==1);
            
        }
        
        
        return result;
    }
};