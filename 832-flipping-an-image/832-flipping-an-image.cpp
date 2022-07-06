class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        
        // 1    1   0
        // 1    0   1
        // 0    0   0
        
        // 1    0   0
        // 0    1   0
        // 1    1   1
        
        // first we need to reverse the rows of array 
        // then we need to invert the bits
        
        int n = image.size();
        
        for( int i = 0 ; i < n ;i++){
            
            int lo = 0 ; 
            int high = n-1;
            
            while( lo < high){
                
                swap( image[i][lo] , image[i][high]);
                lo ++; high--;
                
            }
            
        }
        
        
        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < n ;j ++){
                if( image[i][j] & 1 ){
                    image[i][j] = 0;
                }else{
                    image[i][j] = 1;
                }
            }
        }
        
        return image;
    }
};