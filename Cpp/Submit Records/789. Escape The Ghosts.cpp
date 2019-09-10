/********************************************
作者:Alfeim
题目:逃脱阻碍者
时间消耗:8ms
解题思路:计算阻碍者的离目的地的距离是否大于起始地到目的地的距离即可
相似题目：No.33 搜索旋转排序数组
********************************************/
class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int tmp = abs(target[0]) + abs(target[1]);
        for(auto i : ghosts){
            if(tmp > abs(target[0] - i[0]) + abs(target[1] - i[1]))  return false;
        }
        return true;
    }
};
