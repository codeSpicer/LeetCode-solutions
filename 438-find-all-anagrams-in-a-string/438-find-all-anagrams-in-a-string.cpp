class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> result;
        if( p.size() > s.size()  ){
            return result;
        }
        
        vector<int> freq(26) , ans(26);
        
        int i = 0 ; int j = 0;
        
        for( int k = 0 ; k < p.size() ; k++){
            freq[ s[k] - 'a' ]++;
            j++;
            ans[ p[k]-'a' ]++;
        }
        
        
        if( freq == ans){
            result.push_back(j- p.size());
        }
        
        while( j < s.size() ){
            freq[ s[i] - 'a']--;
            freq[s[j] - 'a']++;
                if( freq == ans){
                    result.push_back(j- p.size()+1);
                }
            i++ ; j++;
        }
        
        for( auto i : freq){
            cout<< i << " ";
        }
        
        return result;
    }
};