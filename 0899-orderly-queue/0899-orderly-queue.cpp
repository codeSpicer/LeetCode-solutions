class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        if( k == 1 ){           // if only 1 char can be moved then the ans will be the lexico smallest rotation of string 
            string ans = s;
            for( int i = 0 ; i < s.length() ; i++){
                string temp = s.substr( i) + s.substr( 0 , i );
                if( temp < ans ){
                    ans = temp;
                }
            }
            return ans;
        }
            // else if more than 1 char can be moved then we can get the sort string as smallest 
        string ans = s;
        sort( ans.begin() , ans.end());
        return ans;
        
        // baaca
        // bacaa
        // bcaaa
        // caaab
        // aaabc
        
        // cdab
        // dabc
        // adbc
        // dbca
        // bdca
        // dcab
        // dabc
        // 
        
        
    }
};