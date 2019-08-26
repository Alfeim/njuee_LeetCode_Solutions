/********************************************
作者:Alfeim
题目:课程表3
时间消耗:368ms
解题思路:贪心算法+哈希表
用一个哈希表记录各个数字的剩余次数
另一个哈希表记录以某个数字为结尾的字符串个数

遍历每一个数字,如果当前数字的次数已经用完就跳过
否则,先查看是否有以该数字-1为结尾的数组,如果有,就让该数字-1
结尾的数组记录-1,并让该数字结尾的数组记录+1

如果没有,就看是否存在该数字+1和+2的数,如果有,将对应的数
的记录各-1,并让以该数字+2为结尾的数组记录+1;

如果还是没有就返回false;
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
