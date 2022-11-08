class MyQueue {
public:
    stack<int>st1,st2;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        
        st1.push(x);
        
    }
    
    int pop() {
        
        int temp = peek();
        
        st2.pop();
        
        return temp;
    }
    
    int peek() {
        
        if(st2.empty()){
            
            int n = st1.size();
            
            for(int i=0;i<n;++i){
                
                st2.push(st1.top());
                st1.pop();
            }
        }
        
        int temp = st2.top();
        
        return temp;
    }
    
    bool empty() {
        
        return st1.empty() && st2.empty();
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