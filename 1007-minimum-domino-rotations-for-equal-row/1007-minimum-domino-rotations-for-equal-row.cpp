class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        // idea is to store the count of dominoes in both array
        // and also have a count of numbers when there are same numbers in both domino
        
        // then we check for 1-6 if any number has total frequency >= tops.size() 
        // we take total frequency from tops + bottoms - same index frequency
        
        int t[7]={};
        int b[7]={};
        int same[7]={};
        
        for( int i= 0 ;i < tops.size() ; i++){
            
            t[tops[i]]++;
            b[bottoms[i]]++;
            
            if( tops[i] == bottoms[i] ){
                same[tops[i]] ++;
            }
            
        }
        
        for( int i = 1 ; i < 7 ; i++){
            
            if( t[i] + b[i] - same[i] >= tops.size() ){
                return (tops.size() - max( t[i] , b[i]));
            }
            
        }
        
        
        return -1;
        
    }
};