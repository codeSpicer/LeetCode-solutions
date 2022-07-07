class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> result;
        
        for( int i = 0 ; i < nums1.size() ; i++){
            
            int greater = -1;
            int index = 0;
            
            while( nums2[index] != nums1[i] ){
                index++;
            }
            
            for( int j = index ; j < nums2.size() ; j++){
                
                if( nums2[j] > nums1[i]){
                    greater = nums2[j];
                    break;
                }
                
            }
            
            result.push_back( greater);
            
        }
        
        return result;
        
    }
};