class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        sort( nums.begin() , nums.end() );
        
        for( int i = 0 ; i < queries.size() ; i++){
            
            int query = queries[i];
            
            int sum = 0;
            int counter = 0;
            while(  counter < nums.size() &&  sum + nums[counter] <= query ){
                sum += nums[counter++];
            }
            queries[i]= counter;
        }
        
        
        return queries;
    }
};