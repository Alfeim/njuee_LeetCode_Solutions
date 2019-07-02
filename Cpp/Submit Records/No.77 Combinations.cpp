/********************************************
作者:Alfeim
题目:组合
时间消耗:95ms
解题思路:回溯,利用对称的push和pop操作可以只用一个临时数组来保存数据(注意应当使用引用)
相似题目:No.46 全排列
********************************************/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        Solve(tmp,1,k,n);
        return res;
    }
    
    void Solve(vector<int> &tmp,int begin,int k,int n){
        if(tmp.size() == k){
            res.push_back(tmp);
            return;
        }
        
        for(int i = begin ; i <= n - ( k - tmp.size()) + 1 ; ++i){
            tmp.push_back(i);
            Solve(tmp,i+1,k,n);
            tmp.pop_back();
        } 
    }
};
