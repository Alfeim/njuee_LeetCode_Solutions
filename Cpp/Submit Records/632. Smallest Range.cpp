/********************************************
作者:Alfeim
题目:最小区间
时间消耗:160ms
解题思路:小顶堆
用一个变量保存临时最大值
********************************************/
class Solution {
public:
    struct Node{
        int val;
        int arrid;
        int numsid;
        Node(int _val,int _arrid,int _numsid):val(_val),arrid(_arrid),numsid(_numsid){};
    };
    
    struct cmp{
        bool operator()(Node a,Node b){
            return a.val > b.val;
        }
    };
    
    void MinArea(vector<int> &a,vector<int> &b){
        if(a[1] - a[0] < b[1] - b[0])
            return;
        else if(a[1] - a[0] == b[1] - b[0]  && a[0] < b[0])
            return;
        
        a[0] = b[0];
        a[1] = b[1];
        return;
    }
    
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Node,vector<Node>,cmp> Q;
        int tmpMax = -100000;
        vector<int> res{-100000,100000};
        vector<int> tmp{0,0};
        
        int k = nums.size();
        for(int i = 0 ; i < k ; ++i){
            Node cur(nums[i][0],i,0);
            Q.push(cur);
            tmpMax = max(nums[i][0],tmpMax);
        }
        
        while(1){
            Node cur = Q.top();
            Q.pop();
            tmp[0] = cur.val;
            tmp[1] = tmpMax;
            MinArea(res,tmp);
            
            cur.numsid++;
            if(cur.numsid >= nums[cur.arrid].size()) break;
            cur.val = nums[cur.arrid][cur.numsid];
            tmpMax = max(tmpMax,cur.val);
            Q.push(cur);
        }
        
        return res;
        
    }
};


