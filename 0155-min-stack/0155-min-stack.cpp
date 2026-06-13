class MinStack {
public:
    stack<pair<int,int>>s;
    MinStack() {}
    
    void push(int value) {
        pair<int,int>m;
        if(!this->s.empty())
          m.second=min(value,this->s.top().second);
        else
          m.second=value;
        m.first=value;
        s.push(m);
    }
    
    void pop() {
       if(!this->s.empty())
         this->s.pop(); 
    }
    
    int top() {
        if(!this->s.empty())
          return this->s.top().first;
        return 0;
    }
    
    int getMin() {
        int val;
        if(!this->s.empty())
          val=this->s.top().second;
        return val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */