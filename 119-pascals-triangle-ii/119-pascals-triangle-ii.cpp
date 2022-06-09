class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> arr(rowIndex +1 , 0);
        
        arr[0] = 1;
        
        for( int i = 1 ;i < rowIndex+1 ;i++){
            for( int j = i ; j >0 ; j--){
                arr[j] += arr[j-1];
            }
        }
        
        return arr;
        
    }
};