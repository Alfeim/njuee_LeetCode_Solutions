/********************************************
作者:Alfeim
题目:有效的括号嵌套深度
时间消耗:32ms
解题思路:栈、贪心
********************************************/
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        
        stack<int> S;
        vector<int> res;
        
        for(int i = 0 ; i < n ; ++i){
            if(S.empty()){
                S.push(0);
                res.push_back(0);
            }else{
                if(seq[i] == '('){
                    int cur = (S.top() == 1) ? 0 : 1;
                    S.push(cur);
                    res.push_back(cur);
                }else{
                    res.push_back(S.top());
                    S.pop();
                }
            }
        }
        
        return res;
        
    }
};
