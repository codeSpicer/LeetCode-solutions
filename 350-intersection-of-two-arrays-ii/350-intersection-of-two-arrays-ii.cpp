class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        // APPROACH 1 would be to sort the 2 arrays
        // use 2 pointers to iterate the arrays and push the value when it is equal in both arrays
        // 6 ms     10.1 MB
        
        // APPROACH 2   would be using a unordered hash map to store values and frequency of elements from 1 array 
        // and then search for the elements of array 2 in the hash map and if 
        // its frequency is more than one add it to the solution vector
        
        int i = nums1.size();
        int j = nums2.size();
        
        vector<int> ans;
        unordered_map<int,int> umap;
        
        for( int x = 0 ; x < i ; x++){
            
            umap[nums1[x]]++;
            
        }
        
        for( int y = 0 ; y < j ; y++){
            
            if( umap[nums2[y]] > 0){
                umap[nums2[y]]--;
                ans.push_back(nums2[y]);
            }
            
        }
        
        
        
        return ans;
    }
};