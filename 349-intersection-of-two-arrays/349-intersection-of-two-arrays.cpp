class Solution {
  public:
    vector < int > intersection(vector < int > & nums1, vector < int > & nums2) {

      // three approaches 
      //-> o(nlogn) o(1) -> sort the arrays and use 2 pointer to iterate both at once
      //-> o( n)  o( n)  -> adding one array to a hashset and then iterrating the other array to find common elements
      //-> o( nlogn) o( 1) ->sort one array then iterate the other to find elements using binary search

      sort(nums1.begin(), nums1.end());
      sort(nums2.begin(), nums2.end());

      vector < int > ans;

      int i = 0, j = 0;
      int n = nums1.size(), m = nums2.size();

      while (i < n && j < m) {

        if (nums1[i] == nums2[j]) {
          ans.push_back(nums1[i]);
          i++;j++;
        } else if (nums1[i] > nums2[j]) {
          j++;
        } else {
          i++;
        }

        while ( i > 0 && i < n && nums1[i] == nums1[i - 1]) {       // need to take special care for pointers in inner while loops
          i++;
        }
        while ( j > 0 && j < m && nums2[j] == nums2[j - 1]) {
          j++;
        }

      }

      return ans;
    }
};