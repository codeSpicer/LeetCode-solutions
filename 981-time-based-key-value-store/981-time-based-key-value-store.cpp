class TimeMap {
public:
    unordered_map< string , vector<pair<int, string>> > keyTime; 
    TimeMap() {
        
        // hashmap with key as key string then its value will be another hashmap with key as timestamp and value as string at that timestamp
        // which would provide with o(1) lookups but the main problem will be to return strings where timestamps are blank
        
        // we can use the first hashmap as it is to map key and value
        // but this time instead of using another hashmap we are using a vector<pair> to store <int, string>
        // if we sort it then we can return the insert position of timestamp if timestamp is not present
        
        // as all timestamps are strictly increasing therefore we dont need to sort the array and can just use binary search to return the ans
        
        
    }
    
    void set(string key, string value, int timestamp) {
        
        keyTime[key].push_back({timestamp , value});
        
    }
    
    string get(string key, int timestamp) {
        
        
        if (keyTime.find(key) == keyTime.end()) {       // no key
            return "";
        }
        
        if (timestamp < keyTime[key][0].first) {     // first timestamp greater than req timestamp
            return "";
        }
        
        int left = 0;
        int right = keyTime[key].size();
        
        while( left < right){
            
            int mid = ( left + right )/2;
            
            if( keyTime[key][mid].first <= timestamp){
                left = mid +1; 
            }else{
                right = mid;
            }
            
        }
        
        return keyTime[key][right-1].second;
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */