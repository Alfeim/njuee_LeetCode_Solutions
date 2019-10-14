/********************************************
作者:Alfeim
题目:距离相等的条形码
时间消耗:308ms
解题思路:大顶堆
********************************************/
class Solution {
public:
    struct node{
        int number;
        int count;
        node(int val,int cnt):number(val),count(cnt){};
    };

    struct cmp{
        bool operator()(node *a,node *b) const{
            return a->count < b->count;
        }; 
    };
    
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if(barcodes.size() <= 2) return barcodes;
        
        //record用于记录每个元素的出现次数 Q为优先级队列
        unordered_map<int,int> record;
        priority_queue<node*,vector<node*>,cmp> Q;
        
        //先计算每个元素的出现次数
        for(auto i : barcodes) record[i]++;
        
        //初始化优先级队列
        for(auto i : record){
            node *cur = new node(i.first,i.second);
            Q.push(cur); 
        }
        
        int n = barcodes.size();
        vector<int> res(n,0);
        int last = 0;
        
        //遍历每一个待填入的位置
        for(int i = 0 ; i < n ; ++i){
            auto firstnode = Q.top();
            Q.pop();
            //如果当前剩余量最多的元素不是上一时刻填入的值,就填入该值
            if(firstnode->number != last){
                res[i] = firstnode->number;
                last = res[i];
                firstnode->count--;    
            }else{//否则填入次大值
                auto secondnode = Q.top();
                Q.pop();
                
                res[i] = secondnode->number;
                last = res[i];
                secondnode->count--;
                if(secondnode->count > 0) Q.push(secondnode);
            }
            
            if(firstnode->count > 0) Q.push(firstnode);
            
        }
        
        return res;
        
        
    }
};
