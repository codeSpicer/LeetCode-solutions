class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        long long int result = 0;
        
        for (auto alpha : columnTitle)
            
            result = result * 26 + alpha - 'A' + 1;
        
        
        return result;
    }
        
};