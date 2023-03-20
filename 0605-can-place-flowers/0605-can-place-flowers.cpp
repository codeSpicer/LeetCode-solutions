class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int counter= 0;
        
        if( flowerbed.size() == 1 && flowerbed[0] == 0){
            return true;
        }
                                                         
        if( flowerbed.size() > 1){
            if( flowerbed[0] == 0 && flowerbed[1] == 0 ){
                counter++;
                flowerbed[0]= 1;
            }
            
            if( flowerbed[flowerbed.size()-1] == 0 && flowerbed[flowerbed.size()-2] == 0 ){
                counter++;
                flowerbed[flowerbed.size()-1] = 1;
            }
        }
        
        for( int i = 1 ; i < flowerbed.size()-1 ; i++){
            
            if( flowerbed[i] == 0){
                
                bool left = (flowerbed[i-1] == 0 );
                bool right = ( flowerbed[i+1] == 0);
                
                if( left && right){
                    counter++;
                    flowerbed[i] = 1;
                }
                
            }
            
        }
        
        if( counter >= n ){
            return true;
        }
        return false;
    }
};