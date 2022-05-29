class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if( image[sr][sc] == newColor){ return image; }   // if pixel is already newcolor
        
        fill( image , sr , sc , newColor , image[sr][sc]);  // depth first search
        
        return image;
        
    }
    
    
    void fill(vector<vector<int>>& image, int sr, int sc, int newColor, int initialColor){
        
        // first check for out of bounds -> then check for initial colour check
        
        if( sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != initialColor ){
            return;     // if anything is true then we return
        }
        
        image[sr][sc] = newColor;       // else we color the pixel to the new color
            
        // and call this fucntion recursively and making it a depth first search
        
        fill( image , sr-1 , sc , newColor , initialColor);
        fill( image , sr+1 , sc , newColor , initialColor);
        fill( image , sr , sc-1 , newColor , initialColor);
        fill( image , sr , sc+1 , newColor , initialColor);
            
    }
    
};
