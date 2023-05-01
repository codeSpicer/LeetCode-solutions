class Solution {
public:
    double average(vector<int>& salary) {
        
        int mini= salary[0];
        int maxi = salary[0];
        
        double sum = 0;
        
        for( const auto& ele : salary){
            
            mini = min( ele , mini);
            maxi = max( ele , maxi);
            sum += ele;
            
        }
        sum -= mini;
        sum-= maxi;
        
        return sum/(salary.size()-2);
        
    }
};