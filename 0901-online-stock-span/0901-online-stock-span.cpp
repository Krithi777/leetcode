class StockSpanner {
public:
    stack<pair<int,int>>s;
    StockSpanner() {}
    
    int next(int price) {
        pair<int,int>m;
        int k=0;
        while(!this->s.empty() && price>=this->s.top().first)
        {
            k+=s.top().second;
            this->s.pop();
        }
        m.first=price;
        m.second=k+1;
        this->s.push(m);
        return m.second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */