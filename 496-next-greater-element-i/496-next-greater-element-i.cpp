class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> result(nums1.size() , -1);
        
        // idea is to use a monotonic stack approach 
        // and help of hashmap to store the indexes of original array element 
        
        unordered_map<int,int> mp;
        for( int i = 0 ; i < nums1.size() ; i++){
            mp[nums1[i]] = i;                       // key => element, value => index of element 
        }
        
        stack<int> st;
        
        for( int i = 0 ;i < nums2.size() ; i++){
            
            while( st.size() && nums2[i] > st.top()){     // when a greater element comes we pop all top elements smaller than current element and assign value in result array 
                result[mp[st.top()]] = nums2[i];
                st.pop();
            }
            if( mp.find(nums2[i]) != mp.end() ){
                st.push(nums2[i]);                  // but if the current element is not in array 1 then we dont push it in stack
            }
            
        }
        
        
            
        return result;
    }
};