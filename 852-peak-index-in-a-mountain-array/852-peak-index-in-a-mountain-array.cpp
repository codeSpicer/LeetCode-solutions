class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int l = 0;
        int r = arr.size()-1;
        
        while( l < r){      // we use  l<r when set l or r to mid to prevent infinite loop
            
            int mid = l+ (r-l)/2;
            
            if(  arr[mid+1] > arr[mid]){
                l = mid+1;
            }else {
                r = mid;
            }
        }
        return l;
        
    }
};