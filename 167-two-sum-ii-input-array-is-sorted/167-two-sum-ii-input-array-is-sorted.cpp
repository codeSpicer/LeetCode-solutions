class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        
        // O(N logN ) approach using binary search
            //      as the array is already sorted we can iterate the array 
            //      and find target-current_value in the rest of array using binary search
            //      it will be called n times in worst case and every call would be of log n time so nlogn

        // linear approach using hash-map-uh        // 2 pass solution
            //      we can add all the elements in the unordered_map
            //      then taking the advantage of constant lookup times
            //      we can easily iterate the array and find of complements with add up to the target number
        
        // the ultimate god of memory saving and one pass -> Two pointer approach
            //     two pointers one at end one at start
            //     if sum of them greater than target then end pointer -- else start pointer ++
            //     EZZ
        
        
        int i = 0;
        int j = num.size()-1;
        
        vector<int> ans;
        
        while( i != j ){
            
            if( num[i] + num[j] == target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }else if( num[i] + num[j] > target){
                j--;
            }else{
                i++;
            }
            
        }
        
        return ans;
        
    }
};
