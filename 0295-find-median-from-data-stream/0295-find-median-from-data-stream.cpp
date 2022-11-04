class MedianFinder {
public:
   
    priority_queue<int>maxHeap;
    
    priority_queue<int, vector<int>, greater<int>>minHeap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        maxHeap.push(num);
        
        int n = maxHeap.size();
        
        int m = minHeap.size();
        
        if(n - m > 1 ){
            
            auto temp = maxHeap.top();
            
            maxHeap.pop();
            
            minHeap.push(temp);
        }
        
        if(m>0 && maxHeap.top() > minHeap.top()){
            
            auto temp = minHeap.top();
            
            auto var = maxHeap.top();
            
            maxHeap.pop();
            maxHeap.push(temp);
            
            minHeap.pop();
            minHeap.push(var);
        }
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size()) return maxHeap.top();
        return (minHeap.top()+maxHeap.top())/2.0;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */