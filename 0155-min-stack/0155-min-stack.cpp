class MinStack {
public:
    stack<int>st,st2;
    
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        
        if(st2.empty()) st2.push(val);
        else{
            if(st2.top() >= val ) st2.push(val); 
        }
    }
    
    void pop() {
        if(st.top() == st2.top()){
            st.pop();
            st2.pop();
        }else{
            st.pop();
        }
        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        
        return st2.top();
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