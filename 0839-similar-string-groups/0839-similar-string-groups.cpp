class Solution {
    
    void bfs(int node , vector<vector<int>> adj ,vector<bool> &visit){
        
        queue<int> q;
        q.push( node);
        visit[node] = true;
        
        while( !q.empty() ){
            int n = q.front();
            q.pop();
            for( const auto& i : adj[n]){
                
                if( !visit[i] ){
                    q.push( i);
                    visit[i] = true;
                }
                
            }
            
        }
        return ;
    }
    
    
    bool isSimilar( string a , string b ){
        int diff=0;
        for( int i = 0 ; i  < a.size() ; i++){
            if( a[i] != b[i]){
                diff++;
            }
        }
        return ( diff == 0 || diff == 2);
    }
    
public:
    int numSimilarGroups(vector<string>& strs) {
        /*
        set<string> s( strs.begin() , strs.end());
        
        int res = 0;
        queue<string> q;
        
        while( !s.empty() ){
            
            q.push( *s.begin() );
            s.erase( *s.begin());
            
            while( !q.empty() ){
                
                string cur = q.front();
                q.pop();
                
                for( int i = 0 ; i < cur.size() ; i++){
                    for( int j = i+1 ;  j < cur.size() ; j++){
                        string temp = cur;
                        swap( temp[i] , temp[j]);
                        if( s.find( temp ) != s.end() ){
                            s.erase( temp);
                            q.push( temp);
                        }
                    }
                }
            }
            res++;
        }
        return res;
        */  //results in time limit exceeded  29/77 testcases
        
        int n = strs.size();
        
        vector<vector<int>> adj(n);
        
        for( int i = 0 ; i < n ; i++){
            for( int j = i+1 ; j < n ; j++){
                if(isSimilar( strs[i] , strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }        
        
        vector<bool> visit( n);
        
        int count = 0;
        
        for( int i = 0 ; i < n ; i++){
            if( !visit[i]){
                bfs( i , adj , visit);
                count++;
            }
        }
        return count;
    }
};