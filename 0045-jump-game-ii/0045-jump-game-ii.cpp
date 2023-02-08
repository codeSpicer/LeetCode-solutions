class Solution {
public:
    int jump(vector<int>& nums) {

//         // idea is to choose the index we jump at by checking from the current pos how far can we go
//         // if we jump to that index
        
//         int start = 0;
//         int jumps = 0;
        
//         for( int i = 0 ; i < nums.size() ; i++){
            
//             if( nums[start] + start >= nums.size() ){
//                 return jumps+1; // last index from where we can jump to end of array
//             }
            
//             // else for the number of indexes we can jump to 
//             // we check which index has potential to reach the farthest
//             int farthest = start+ nums[start];
//             int index = start;
//             for( int j = start ; j < nums.size() && j < start+nums[start] ; j++){
//                 if( start+ nums[j] > farthest ){
//                     farthest = start + nums[j];
//                     index = j;
//                 }
//             }
//             start = index;
//             jumps++;
            
//         }
        
//         return jumps;
        
        int l = 0;
        int r = 0;
        int jumps = 0;
        
        while( r < nums.size()-1){
            
            int windowR = r;
            for( int  i = l ; i <= r ; i++){
                if( nums[i]+i > windowR ){
                    windowR = nums[i]+i;
                }
            }
            l = r+1;
            r = windowR;
            jumps++;
            
        }
        return jumps;
    }
};