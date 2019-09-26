/********************************************
作者:Alfeim
题目:股票价格跨度
时间消耗:404ms
解题思路:栈
********************************************/
class StockSpanner {
public:
    struct node{
        int price;
        int counts;
        node(int _price):price(_price),counts(1){};
    };
    
    StockSpanner() {
    
    }
    
    int next(int price) {
        node* today = new node(price);

        while(!record.empty()){
            auto last = record.top();
            if(last->price > today->price) break;
            today->counts += last->counts;
            record.pop();
        }
        
        record.push(today);
        return (record.top())->counts;
    }

private:
    stack<node*> record;  //维护一个递减栈
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
