class MyQueue {
public:
    MyQueue() {
    }
    
    stack<int>st;
    
        stack<int>st2;
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        // if(st.empty()){
        //     return 
        // }
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        int ret=  st2.top();
        st2.pop();
        while(!st2.empty()){
            st.push(st2.top());
            st2.pop();
        }
        return ret;        
    }
    
    int peek() {
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        int ret=  st2.top();
        while(!st2.empty()){
            st.push(st2.top());
            st2.pop();
        }
        return ret;    
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */