class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> mergedIntervals;        // return array
 
        if( intervals.size() == 0){
            return mergedIntervals;                 // edge case
        } 
        
        sort( intervals.begin() , intervals.end()); // sorting by start time
        
        vector<int>tempInterval = intervals[0];     // storing first interv in temp var
        
        for( int i = 0 ;i < intervals.size() ; i++){
            
            // we compare the temp interval with sorted intervals one by one 
            // if start time of next interval if less than end time of temp 
            // we merge interval
            // once the interval do not overlap we push the temp to the result arr.
            
            if( tempInterval[1] >= intervals[i][0]){
                if( tempInterval[1]<intervals[i][1]){
                    tempInterval[1]= intervals[i][1];
                }
            }else{
                mergedIntervals.push_back(tempInterval);
                tempInterval = intervals[i];
            }
            
        }
        mergedIntervals.push_back(tempInterval);        // pushing last interval
        
        return mergedIntervals;
        
    }
};