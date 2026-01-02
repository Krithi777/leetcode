class MyQueue {
    stack<int>s,p;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        if(p.empty())
        {
          while (!s.empty())
         {
            p.push(s.top());
            s.pop();
         }
        }
        int k=p.top();
        p.pop();
        return k;
    }
    
    int peek() {
        if(p.empty())
        {
          while (!s.empty())
         {
            p.push(s.top());
            s.pop();
         }
        }
        return p.top();
    }
    
    bool empty() {
        return (s.empty() && p.empty());
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