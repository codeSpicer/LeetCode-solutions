class Solution {
public:
    int partitionString(string str) {
        
        int partitions = 1;
        
        unordered_set<int> s; 
        
        int l , r = 0;
        
        while( r < str.size()){
            
            if( s.find(str[r]) != s.end() ){
                partitions++;
                s.clear();
                l = r;
            }else{
                s.insert( str[r++]);
            }
            
        }
        return partitions;
    }
};