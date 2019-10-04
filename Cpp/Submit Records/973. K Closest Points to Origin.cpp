/********************************************
作者:Alfeim
题目:最接近原点的K个点
时间消耗:472ms
解题思路:自定义排序
********************************************/
class Solution {
public:
    struct cmp{
      bool operator()(const vector<int> &node1,const vector<int> &node2) const{
           int distance1 = pow(node1[0],2) + pow(node1[1],2);
           int distance2 = pow(node2[0],2) + pow(node2[1],2);
           return distance1 < distance2;
      } 
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        sort(points.begin(),points.end(),cmp());
        for(int i = 0 ; i < K ; ++i) res.push_back(points[i]);
        return res;
    }
};
