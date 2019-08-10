/********************************************
作者:Alfeim
题目:供暖期
时间消耗:88ms
解题思路:二分查找..只需要找到每一间房子之前和
之后的供暖器,去二者距离中最小即是当前半径;然后取
当前半径中的最大者
********************************************/
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if(houses.empty())
            return 0;
        
        int res = 0;
        int m = houses.size();
        int n = heaters.size();
        sort(heaters.begin(),heaters.end());
        for(int i = 0 ; i < m ; ++i){
            auto it = lower_bound(heaters.begin(),heaters.end(),houses[i]);
            int radius_right = it == heaters.end() ? INT_MAX : *it - houses[i];
            int radius_left = it == heaters.begin()? INT_MAX : houses[i] - *(--it);
            int tmp_radius = min(radius_left,radius_right);
            res = max(res,tmp_radius);
        }

        return res;
    }
};
