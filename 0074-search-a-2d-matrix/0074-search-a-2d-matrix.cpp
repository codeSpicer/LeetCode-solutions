class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // if imagined as a one d array then
        // first index will be 0 and last index will be m*n-1
        int m = matrix.size();
        int n = matrix[0].size();
        
        int low = 0 ; 
        int high = (n*m)-1;
        
        while( low <= high){
            int mid = ( low + high )/2;
            int i = mid/n;
            int j = mid%n;
            
            if( matrix[i][j] < target){
                low = mid+1;
            }else if( matrix[i][j] > target){
                high = mid-1;
            }else{
                return true;
            }
            cout<< matrix[i][j] << " ";
        }
        return false;
    }
};