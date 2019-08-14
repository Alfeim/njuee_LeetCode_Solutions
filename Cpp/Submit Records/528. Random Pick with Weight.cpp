/********************************************
作者:Alfeim
题目:按权重随机选择
时间消耗:280ms
解题思路:按照累计和划分
********************************************/
class Solution {
public:
    Solution(vector<int>& w) {
        int n = w.size();
        sum = 0;
        for(int i = 0 ; i < n ; ++i){
            sum += w[i];
            M[sum] = i;
        } 
    }
    
    int pickIndex() {
        int number = rand()%(sum) + 1;
        auto it = M.lower_bound(number);
        return it->second;
    }
    
    int sum;
    map<int,int> M;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
