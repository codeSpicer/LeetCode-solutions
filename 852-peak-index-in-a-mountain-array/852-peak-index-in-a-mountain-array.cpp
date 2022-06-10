class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int l = 0;
        int r = arr.size()-1;
        
        while( l <= r){
            
            int mid = l+ (r-l)/2;
            
            if( mid>0 && arr[mid-1] > arr[mid]){
                r = mid-1;
            }else if( mid<arr.size() && arr[mid+1] > arr[mid] ){
                l = mid+1;
            }else{
                return mid;
            }
            
        }
        return l;
        
    }
};