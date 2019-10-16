/********************************************
作者:Alfeim
题目:拼车
时间消耗:16ms
解题思路:优先级队列
********************************************/
class Solution {
public:
    struct node{
        int dst;
        int count;
        node(int _dst,int _count):dst(_dst),count(_count){};
    };
    
    struct cmp{
        bool operator()(const node* n1,const node *n2) const{
            return n1->dst > n2->dst;
        };    
    };
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),[](vector<int> &v1,vector<int> &v2){ return v1[1] < v2[1];});
        
        priority_queue<node*,vector<node*>,cmp> Q;
        
        int sum = 0;
        for(auto i : trips){
            
            while(!Q.empty() && i[1] >= (Q.top())->dst){
                sum -= (Q.top())->count;
                Q.pop();
            }
            
            sum += i[0];
            
            if(sum > capacity) return false;   
            
            Q.push(new node(i[2],i[0]));
        }
        
        return true;
        
    }
};
