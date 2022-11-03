class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        unordered_map<string , int> freq;
        int result = 0;
        bool middle = 0;
        
        for( const auto& word : words){
            
            string temp = word;
            swap( temp[0] , temp[1]);
            
            if( freq[temp] > 0 ){
                freq[temp]--;
                result+=4;
            }else{
                freq[word]++;
            }            
        }
        
        for( const auto& word : words){
            
            if( word[0] == word[1] && freq[word] % 2 == 1 ){
                middle= 1;
                break;
            }
        }
        
        if( middle){
            result +=2;
        }
        
        return result;
        
    }
};