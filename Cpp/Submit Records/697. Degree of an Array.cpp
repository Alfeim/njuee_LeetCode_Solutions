/********************************************
作者:Alfeim
题目:数组的度
时间消耗:44ms
解题思路:自定义排序
********************************************/
class Solution {
public:
    struct node{
        int begin;
        int end;
        int degree;
        node(int _begin):begin(_begin),end(-1),degree(0){};
        
    };
    
    struct cmp{
        bool operator()(node* a,node* b){
            if(a->degree > b->degree) return true;
            if(a->degree < b->degree) return false; 
            return a->end - a->begin < b->end - b->begin;
        }
    };

    
    int findShortestSubArray(vector<int>& nums) {
        vector<node*> V(50001,nullptr);
        int n = nums.size(); 
        if(n == 0) return 0;
        
        for(int i = 0 ; i < n ; ++i){
            if(!V[nums[i]])  V[nums[i]] = new node(i);   
            V[nums[i]]->end = i;
            V[nums[i]]->degree++;
        }
        
        vector<node*> tmp;
        
        for(auto i : V) if(i != nullptr) tmp.push_back(i);

        sort(tmp.begin(),tmp.end(),cmp());
        
        return tmp[0]->end - tmp[0]->begin + 1 ;      
        
    }
};
