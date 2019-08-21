/********************************************
作者:Alfeim
题目:函数独占时间
时间消耗:52ms
解题思路:栈
********************************************/
class Solution {
public:
    stack<int> S;
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> record(n + 1,0);
        int last_time = 0;
        bool last_flag = false;
        int id = 0,time = 0;
        for(auto i : logs){
            bool flag;
            get_info(i,id,time,flag);
            if(S.empty())
                S.push(id);
            else{
               int last_id = S.top();
               record[last_id] += time - last_time;
               if(flag){ 
                   if(!last_flag) record[last_id] -= 1;
                   S.push(id);
               }else{
                   if(last_flag) record[last_id] += 1;
                   S.pop();               
               }
            }
            last_time = time;
            last_flag = flag;
        }

        vector<int> res;
        for(auto i : record){
          if(i > 0) res.push_back(i); 
        } 
        return res;
        
    }
    
    void get_info(string &log,int &id,int &time,bool &flag){
        int n = log.size();
        int i = 0;
        for(; i < n && log[i] != ':';i++);
        id = stoi(log.substr(0,i));
        int j = n - 1;
        for(; j >= 1 && log[j-1] != ':';j--);
        time = stoi(log.substr(j));
        flag = log[i+1] == 's' ? true : false;
    
        return;
    }
    
    
};
