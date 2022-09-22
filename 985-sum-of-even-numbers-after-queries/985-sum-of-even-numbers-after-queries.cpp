class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int sum = 0;
        
        for( int i = 0 ; i < nums.size() ; i++){
            if( nums[i]%2 == 0){
                sum += nums[i];
            }
        }
        
        vector<int> ans;
        
        for( int i = 0 ; i < queries.size() ; i ++){
            
            int index = queries[i][1];  // 0
            int query = queries[i][0];  // 1
            int temp = nums[index];     // 1
            
            if( nums[index] % 2 == 0){      // if number initially is even
                
                nums[index] += query ;
                
                // if it turns to even then we do the same change to sum
                if( nums[index] % 2 == 0 ){
                    sum += nums[index] - temp;
                    
                }else{  // if it turns odd we substract the initial number from sum
                    sum -= temp;
                }
                
            }else{              // if number initially is odd
                 // if it stays even then do nothing
                // if it becomes even then add that value to sum
                nums[index] += query ;
                if( nums[index] % 2 == 0){
                    sum += nums[index];
                }
            }
            
            ans.push_back(sum);
            
        }
        
        return ans;
    }
};