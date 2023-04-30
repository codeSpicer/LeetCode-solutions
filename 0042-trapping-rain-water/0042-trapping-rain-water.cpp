class Solution {
public:
    int trap(vector<int>& height) {
        
        
        int n = height.size();
        vector<int> sums(n);
        
        int curMax = 0;
        sums[0] = 0;
        
        for( int i = 1 ; i < n ; i++){
            curMax = max( height[i-1] , curMax);
            sums[i] = curMax;
        }
        
        
        sums[n-1] = 0;
        curMax = 0;
        
        int res = 0;
        for( int i = n-2  ; i>0 ; i--){
            curMax =  min( sums[i] , max( height[i+1] , curMax));
            sums[i] = curMax;
            res += max( sums[i]-height[i] , 0);
        }
        
        
        return res;
    }
};