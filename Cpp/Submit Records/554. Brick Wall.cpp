/********************************************
作者:Alfeim
题目:砖墙
时间消耗:72ms
解题思路:利用map对缝隙位置自动排序:

先遍历每一行的缝隙位置,并将其存入map中,
map的key表示该距离的缝隙一共有多少个，那么对于每一个位置的缝隙，
其穿过的砖块数目也就是用行数减去缝隙数即可
********************************************/
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int,int> record;
        int m = wall.size();
        int sum = 0;
        for(int i = 0 ; i < m ; ++i){
            int n = wall[i].size();
            for(int j = 0 ; j < n - 1 ; ++j){
                sum += wall[i][j];
                record[sum]++;
            }
            sum = 0;
        }
        
        int res =  m;
        for(auto i : record){
            res = min(m - i.second,res);
            if(res == 0) return 0;
        }
        return res;
    }
};
