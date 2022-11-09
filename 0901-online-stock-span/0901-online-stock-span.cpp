class StockSpanner {
public:
    
    stack<pair<int,int>> prices;
        
    StockSpanner() {
        // it is  monotonic stack question where we maintain a stack with increasing elements
        // and their span as <int,int>
        // when we pop out elements smaller then cur element from stack
        // we increase the current number's span and store it along side the number
        // so that if we find any number greater than cur num we add cur nums span to that number
    }
    
    int next(int price) {
        
        // time complexi O( 2N);
        // space complex O(N);
        
        int ans = 1;
        
        while( !prices.empty() && prices.top().first <= price){
            ans += prices.top().second;
            prices.pop();
        }
        prices.push( {price , ans} );
        
        return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */