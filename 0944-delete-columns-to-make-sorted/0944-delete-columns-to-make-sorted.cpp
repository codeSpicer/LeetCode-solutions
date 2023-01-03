class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int result = 0;
        
        int size = strs[0].length();
        
        for( int i = 0 ; i < size ; i++){
            for( int j = 1 ; j < strs.size() ; j++){
                if( strs[j][i] < strs[j-1][i] ){
                    result++;
                    break;
                }
            }
        }
        
        
        return result;
    }
};