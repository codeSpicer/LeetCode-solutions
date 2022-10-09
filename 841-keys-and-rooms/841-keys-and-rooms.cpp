class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        unordered_set<int> s;
        s.insert(0);
        
        for( int i = 0 ; i < rooms[0].size() ; i++ ){
            s.insert( rooms[0][i]);
            util( rooms , s , rooms[0][i]);
        }
        
        if( s.size() == rooms.size()){
            return true;
        }
        return false;
        
    }
    
    void util( vector<vector<int>> rooms ,unordered_set<int> &s , int index ){
        
        for( int i = 0 ; i < rooms[index].size() ; i++){
            if( s.find(rooms[index][i]) == s.end()){
                s.insert( rooms[index][i] );
                util( rooms , s , rooms[index][i]);
            }
        }
        return;
    }
    
};