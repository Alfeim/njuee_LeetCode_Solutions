/********************************************
作者:Alfeim
题目:与目标颜色间的最短距离
时间消耗:800ms
解题思路:二分搜索
********************************************/
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<int> res;
        set<int> color1;color1.insert(-100000);color1.insert(100001);
        set<int> color2;color2.insert(-100000);color2.insert(100001);
        set<int> color3;color3.insert(-100000);color3.insert(100001);

        int n = colors.size();

        for(int i = 0 ; i < n ; ++i){
            if(colors[i] == 1) color1.insert(i);
            else if(colors[i] == 2) color2.insert(i);
            else color3.insert(i);
        }

        for(auto i : queries){
            
            if(colors[i[0]] == i[1]) res.push_back(0);
            else{
                int distance1;
                int distance2;
                if(i[1] == 1){
                    auto next = color1.lower_bound(i[0]);
                    auto last = next;last--;
                    distance1 = abs(i[0] - *last);
                    distance2 = *next - i[0];
                }else if(i[1] == 2){
                    auto next = color2.lower_bound(i[0]);
                    auto last = next;last--;
                    distance1 = abs(i[0] - *last);
                    distance2 = *next - i[0];
                }else{
                    auto next = color3.lower_bound(i[0]);
                    auto last = next;last--;
                    distance1 = abs(i[0] - *last);
                    distance2 = *next - i[0];
                }

                int ans = min(distance1,distance2);
                if(ans > 50000) res.push_back(-1);
                else res.push_back(min(distance1,distance2));
            }
        }

        return res;

    }
};
