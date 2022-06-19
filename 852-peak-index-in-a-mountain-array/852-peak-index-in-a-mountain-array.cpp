class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int l = 1;
        int r = arr.size()-2;
        
        
        while( l <= r){
            
            int mid = (l+r)/2;
            
            if( arr[mid-1] > arr[mid]){
                r= mid-1;
            }else if( arr[mid+1] > arr[mid]){
                l= mid+1;
            }else{
                return mid;
            }
            
        }

        return -1;
    }
};