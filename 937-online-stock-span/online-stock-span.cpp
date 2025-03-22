class StockSpanner {
private:
    stack<pair<int,int>>Stk_Span; //Stack of Pairs (Today's_Price, Today's Index)   

public:
    StockSpanner() {
    }
    
    int next(int price) {
     int Days_Count=1; // Start with the current day
     while(!Stk_Span.empty() && price >= Stk_Span.top().first ){
        Days_Count += Stk_Span.top().second; // Add the span of the popped element
        Stk_Span.pop();
     }
     Stk_Span.push({price, Days_Count}); 
     return Days_Count;   
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */