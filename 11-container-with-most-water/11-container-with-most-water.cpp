class Solution {
public:
    int maxArea(vector<int>& height) {
        
        // idea is to use 2 pointers and get the area by taking the lower height amoung the 2
        // and multiplying it with the distance between them
        // we move the pointer which is smaller so that we save our pointer with higher value/potenital
        
        int result =0;
        
        int i = 0; int j = height.size()-1;
        
        int temp_area = 0;
        
        while( i < j){
            
            temp_area = max( temp_area , (j-i)* min(height[i],height[j]));
            
            result = max( result , temp_area);
            
            if( height[i] < height[j]){
                i++;
            }else{
                j--;
            }
            
        }
        
        return result;
        
    }
};