class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // similar problem to search in a 2d matrix
        // binary search app would would
        
        // but if you look closely , from the last element of 0th row
        // the whole matrix looks like a binary tree 
        // and we can iterate to find our element in O(n+m);
        
        int m = matrix.size();
        int n = matrix[0].size();
         
        int i = 0;int j = n-1;
        
        while( i < m && j >= 0 ){
            if( matrix[i][j] > target){
                j--;
            }else if (matrix[i][j] < target){
                i++;
            }else{
                return true;
            }
        }
        
        return false;
        
    }
};