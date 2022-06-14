class Solution {
public:
    int trap(vector<int>& height) {
        
        if( height.size() < 1){
            return 0;
        }
        
        // 0 1 1 2 2 2 2 3 3 3 3 3
        // 3 3 3 3 3 3 3 3 2 2 2 1
        
        // basic idea is to have 2 arrays namely left_max_so_far and right_max_so_far
        // then we substract the minimum of them with current height of bar
        // if it is positive then we add it to our total traped water sum
        
        vector<int> left(height.size());
        vector<int> right(height.size());
        int total= 0;
        int temp=0;
        
        for( int i = 0 ;i < height.size() ; i++){     // making left_max_sofar
            temp = max( temp , height[i]);
            left[i] = temp;
        }
        
        temp=0;
        for( int i = height.size()-1 ; i >=0 ;i--){     // making right max so far
            temp = max( temp , height[i]);
            right[i] = temp;
        }
        
        
        for( int i = 0 ;i < height.size() ; i++){
            temp =  min( left[i] , right[i]) - height[i] ;
            
            if( temp >0 ){
                total += temp;
            }
            
        }       
        
        return total;
        
    }
};