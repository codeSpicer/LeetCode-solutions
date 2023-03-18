class BrowserHistory {
    stack<string> history;
    stack<string> future;
    string current;
public:
    BrowserHistory(string homepage) {
        current = homepage;
    }
    
    void visit(string url) {
        future = stack<string>();   // empties the future if there was any element
        history.push(current);
        current = url;
    }
    
    string back(int steps) {
        while( steps > 0 && !history.empty() ){
            future.push(current);
            current = history.top();
            history.pop();
            steps--;
        }
        return current;
    }
    
    string forward(int steps) {
        while( steps > 0 && !future.empty() ){
            history.push( current );
            current = future.top();
            future.pop();
            steps--;
        }
        return current;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */