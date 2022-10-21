struct Node{
  
    Node *links[26];
    bool flag = false;
    
    bool containsKey( char ch){
        return links[ch - 'a'] != NULL;     // returns true if key is not null
    }
    
    void put( Node* node , char ch){
        links[ch - 'a'] = node;     // puts reference to a new node in links array
    }
    
    Node* get( char ch){
        return links[ch-'a'];       // returns link to next char
    }
    
    void setEnd(){
        flag = true;
    }

    bool isEnd( ){
        return flag;
    }
    
};

class Trie {
private: Node* root;
    
public:
    Trie() {
        root = new Node();       // inits a new root node
    }
    
    void insert(string word) {
        Node* temp = root;
        
        for( const auto& ch : word){        // for every char in word
            if( !temp->containsKey(ch)){
                temp->put(  new Node() , ch);       // if temp does not contain link in links array
                                                    // we make a new node and put it in links array
            }
            temp = temp->get( ch);                  // move to the next link
        }
        temp->setEnd();                         // when whole word is added then we mark flag as true
    }
    
    bool search(string word) {
        
        Node* temp = root;
        
        for( const auto& ch : word){
            if( !temp->containsKey(ch)){
                return false;                       //  if trie does not contain link for a char in word then return false
            }
            temp = temp->get(ch);
        }   
        return temp->isEnd();                   // return true if current node is end of any word
        
    }
    
    bool startsWith(string prefix) {
        
        
        Node* temp = root;
        
        for( const auto& ch : prefix){
            if( !temp->containsKey(ch)){
                return false;               // if link doesnot exist for any word then we return false
            }
            temp = temp->get(ch);
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */