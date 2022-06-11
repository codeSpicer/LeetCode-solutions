class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        // basic idea is to use the sorted value of strs as keys and store the values of strs
        // if 2 strs are anagram then they get stored under one key
        // and we push that vector in the answers vector
        
        unordered_map< string , vector<string>> map;    // key=sorted val -> value=string
        
        vector<vector<string>> result;
        
        for( int i = 0 ;i < strs.size(); i++){
            
            string temp = strs[i];      // storing key and sorting
            sort(temp.begin() , temp.end());
            
            map[temp].push_back(strs[i]);   // adding value to sorted key
            
        }       
        
        // for( int i = 0 ;i < map.size(); i++){
        //     result.push_back(map[i].second);
        // }
        for( auto &map : map){          
            result.push_back(map.second);       // using auto to iterate map and push in ans
        }
        
        return result;
        
    }
};