class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // o( log(m) + log(n) ) probably hehe
        // as the matrix is sorted row wise as well as column wise we can apply binary search
        // first to find the target row which would have the element and then
        //search element in that row
        
        // also another o(m+n) approach would be to see the matrix as an binary tree
        // the arr[0][last] element would be the root and if current element is bigger than target
        // we go left (col--) else we go right ( row++) and we would find the target.
        
        // also there is this way matrix[mid/n][mid%n]
        
    if (matrix.size() == 0 || matrix[0].size() == 0)
    {
        return false;
    }

    int low;
    int high;

    // first search in first column, use binary search
    for (low = 0, high = matrix.size() - 1; low <= high;)
    {
        int middle = (low + high) / 2;
        if (matrix[middle][0] < target)
        {
            low = middle + 1;
        }
        else if (matrix[middle][0] > target)
        {
            high = middle - 1;
        }
        else
        {
            return true;
        }
    }

    // when above loop ends, search in row[high]
    int row = high;
    if (row >= 0)
    {
        for (low = 0, high = matrix[row].size() - 1; low <= high;)
        {
            int middle = (low + high) / 2;
            if (matrix[row][middle] < target)
            {
                low = middle + 1;
            }
            else if (matrix[row][middle] > target)
            {
                high = middle - 1;
            }
            else
            {
                return true;
            }
        }
    }

    return false;
}
};