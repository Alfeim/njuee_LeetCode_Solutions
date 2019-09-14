/********************************************
作者:Alfeim
题目:会议室2
时间消耗:20ms/32ms
解题思路:优先级队列/DFS
********************************************/

//优先级队列解法,小顶堆
//堆顶存储的是最近结束时间
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>&b){
            return a[0] < b[0];
        });
        priority_queue<int, vector<int>, greater<int>> heap;
        for (int i = 0; i < intervals.size(); i++) {
            if (!heap.empty() && heap.top() <= intervals[i][0]) {
                heap.pop();
            }
            heap.push(intervals[i][1]);
        }
        return heap.size();
    }
};

//DFS
class Solution {
public:
    int res;
    int minMeetingRooms(vector<vector<int>>& intervals) {
        res = 0;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<bool> visited(n,false);

        for(int i = 0 ; i < n ; ++i){
            if(!visited[i]){
                visited[i] = true;
                dfs(visited,intervals,i);
                res++;
            } 
        }
        
        return res;
    }
    
    void dfs(vector<bool> &visited,vector<vector<int>>& intervals,int pos){
        int n = intervals.size();
        for(int i = pos + 1 ; i < n ; ++i){
            if(!visited[i] && intervals[i][0] >= intervals[pos][1]){
                visited[i] = true;
                dfs(visited,intervals,i);
                break;
            }
        }   
        return;
    }
    
};
