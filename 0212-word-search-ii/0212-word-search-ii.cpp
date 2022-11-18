class TrieNode
{
    friend class Trie;
    unordered_map<char, TrieNode*> next;
};

class Trie
{
private:
    TrieNode* root;
public:

    const char END_OF_SEQ = '\0';

    Trie()
    {
        this->root = new TrieNode();
    }

    Trie(vector<string>& words)
    {
        this->root = new TrieNode();
        for (string word : words) this->insert(word);
    }

    void insert(string& word)
    {
        TrieNode* node = root;
        for (char ch : word)
        {
            if (!node->next.count(ch))
                node->next[ch] = new TrieNode();
            node = node->next[ch];
        }
        node->next[END_OF_SEQ] = new TrieNode();
    }

    bool search(string& word) 
    {
        TrieNode* node = root;
        for (char ch : word)
        {
            if (!node->next.count(ch)) return false;
            node = node->next[ch];
        }
        if (node->next.count(END_OF_SEQ))
            return true;
        else
            return false;
    }

    bool starts(string& prefix) 
    {
        TrieNode* node = root;
        for (auto ch : prefix)
        {
            if (!node->next.count(ch)) return false;
            node = node->next[ch];
        }
        return true;
    }

    void remove(string& word)
    {
        TrieNode* node = root;
        vector<pair<char,TrieNode*>> nodes;
        for (char ch : word)
        {
            if (!node->next.count(ch)) return;
            node = node->next[ch];
            nodes.emplace_back(ch, node);
        }
        char ch = END_OF_SEQ;
        if (node->next.count(ch))
        {
            while (!nodes.empty())
            {
                auto [c, n] = nodes.back(); nodes.pop_back();
                if (n->next[ch]->next.empty()) n->next.erase(ch);
                ch = c;
            }
        }
    }
};

class Solution 
{
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        int m = board.size(), n = board[0].size();
        Trie trie(words);
        vector<string> seen;
                
        vector<pair<int,int>> dirs = {{0,-1},{0,1},{-1,0},{1,0}};

        function<void(string, vector<vector<char>>&, int, int)> dfs;
        dfs = [&](string p, vector<vector<char>>& b, int x, int y)
        {
            char ch = '#';
            swap(ch, b[x][y]);
            
            if (trie.search(p)) 
                seen.push_back(p), trie.remove(p);

            for (auto[ii,jj] : dirs)
            {
                int i = x + ii, j = y + jj;
                if (0 <= i && i < m && 0 <= j && j < n)
                    if (b[i][j] != '#')
                    {
                        string pp = p + b[i][j];
                        if (trie.starts(pp))
                            dfs(pp, b, i, j);
                    }
            }
            
            swap(ch, b[x][y]);
        };
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                dfs(string(1,board[i][j]), board, i, j);
        
        return seen;
    }
};