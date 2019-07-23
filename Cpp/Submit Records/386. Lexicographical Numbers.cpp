/********************************************
作者:Alfeim
题目:字典序排数
时间消耗:82ms
解题思路:递归
********************************************/
class Solution {
public:
    vector<int> res;
    vector<int> lexicalOrder(int n) {
        for(int i = 1 ; i <= 9;++i){
            if(i > n)
                break;
            res.push_back(i);
            Solve(i,n);
        }
        return res;
    }
    
    void Solve(int begin, int n){
        if(begin > n)
            return;
        begin *= 10;
        int end = begin + 9;
        while(begin <= n && begin <= end){
            res.push_back(begin);
            Solve(begin++,n);
        }
    }
};
