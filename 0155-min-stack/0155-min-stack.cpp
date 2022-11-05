class MinStack {
public:
    vector<int>st;
    
    MinStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        
        int n = st.size(),a = INT_MAX;
        
        for(int i=0;i<n;++i){
            a = min(a,st[i]);
        }
        
        return a;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */