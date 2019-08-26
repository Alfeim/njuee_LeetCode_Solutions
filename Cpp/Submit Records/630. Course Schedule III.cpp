/********************************************
作者:Alfeim
题目:课程表3
时间消耗:368ms
解题思路:贪心算法+大顶堆
如果遇到一个课程无法满足条件 比较堆顶元素
如果堆顶元素的时间更长就将其弹出并压入新元素
********************************************/
class Solution {
public:
    struct cmp{
        bool operator()(vector<int> &v1,vector<int> &v2){
            if(v1[1] < v2[1]) return true;
            else if(v1[1] == v2[1]) return v1[0] < v2[0];
            return false;
        }
    };
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp());
        priority_queue<int,vector<int>,less<int>> Q;
        int n = courses.size();
        int last = 0;
        for(int i = 0 ; i < n ; ++i){
            if(courses[i][0] > courses[i][1]) continue;
            if(last + courses[i][0] <= courses[i][1]){
                Q.push(courses[i][0]);
                last += courses[i][0];
            }else{
                if(Q.top() >= courses[i][0]){
                    last -= Q.top();
                    last += courses[i][0];
                    Q.pop();
                    Q.push(courses[i][0]); 
                }
            }
        }
        
        return Q.size();
        
    }
};
