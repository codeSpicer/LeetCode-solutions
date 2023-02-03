class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        // m means majority element and v means votes of the majority element
        int m1 = -1;
        int m2 = -1;
        int v1 =0;
        int v2 = 0;
        
        for( const auto& ele : nums){
            
            if( ele == m1 ){
                v1++;
            }else if( ele == m2 ){
                v2++;
            }else if( v1 == 0 ){
                m1 = ele;
                v1 = 1;
            }else if( v2 == 0){
                m2 = ele;
                v2 = 1;
            }else{
                v1--; v2--;
            }
            
        }
        
        // once we have 2 elements we check if they are actually majority >= n/3 
        v1 = 0;
        v2 = 0;
        
        for( const auto& i : nums){
            if( i == m1 ){
                v1++;
            }else if( i == m2 ){
                v2++;
            }
        }
        
        vector<int> result;
        if( v2 > nums.size() /3){
            result.push_back( m2);
        }
        if( v1 > nums.size() /3){
            result.push_back( m1);
        }
        
        return result;
    }
};