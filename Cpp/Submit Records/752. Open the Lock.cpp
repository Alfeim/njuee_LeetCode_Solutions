/********************************************
作者:Alfeim
题目:打开转盘锁
时间消耗:328ms
解题思路:BFS
这题的思路其实和单词接龙非常像,特别是求"最短步数"的问题,往往BFS非常直观(因为BFS每次迭代都算1步);当然,如果用DFS也可以,只不过要维护一个全局变量。

为了进行剪枝，我们需要借助哈希表，一个用于存储"禁用的字符串"，一个用于存储"遍历过的字符串"，如果在BFS时遇到这两类记录就直接跳过(因为被禁用的是
不允许作为中间状态出现的,同时,类似最短路径原理,很容易证明如果先前遍历过某个节点，而现在又遍历到了，那么最短路径一定不是这一条)
********************************************/
class Solution {
public:
    queue<string> Q;
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> records;
        unordered_set<string> visited;
        for(auto i : deadends) records.insert(i);
        if(records.count("0000") > 0 || records.count(target) > 0) return -1;
        
        visited.insert("0000");
        Q.push("0000");
        int step = 0;
        while(!Q.empty()){
            int size = Q.size();
            while(size--){
                auto curStr = Q.front();
                Q.pop();
                if(curStr == target) return step;
                for(int i = 0 ; i < 4 ; ++i){
                    string tmp1(curStr);
                    string tmp2(curStr);
                    tmp1[i] = tmp1[i] == '9' ? '0' : tmp1[i] + 1;
                    tmp2[i] = tmp2[i] == '0' ? '9' : tmp2[i] - 1;
                    if(visited.count(tmp1) == 0 && records.count(tmp1) == 0){
                        visited.insert(tmp1);
                        Q.push(tmp1);
                    }
                    if(visited.count(tmp2) == 0 && records.count(tmp2) == 0){
                        visited.insert(tmp2);
                        Q.push(tmp2);
                    }                
                }
            }
            step++;
        }
        
        return -1;
        
    }
};
