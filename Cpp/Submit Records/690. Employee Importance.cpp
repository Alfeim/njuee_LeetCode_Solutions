/********************************************
作者:Alfeim
题目:员工的重要性
时间消耗:36ms
解题思路:BFS
********************************************/
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        queue<int> Q;
        unordered_set<int> visited;
        unordered_map<int,Employee*> workers;
        int res = 0;
        
        
        for(auto i : employees){
            workers[i->id] = i;     
        }
        
        
   
        Q.push(id);
        visited.insert(id);
        
        while(!Q.empty()){
            int size = Q.size();
            while(size--){
                auto cur = workers[Q.front()];
                Q.pop();
                res += cur->importance;
                for(auto i : cur->subordinates){
                    if(!visited.count(i)) Q.push(i);
                }
            }   
        }
        
        return res;
        
    }
};
