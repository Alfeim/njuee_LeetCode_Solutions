/********************************************
作者:Alfeim
题目:在系统中查找重复文件
时间消耗:202ms
解题思路:哈希表
********************************************/
class Solution {
public:
    unordered_map<string,vector<string>> record;
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        for(auto i : paths) Solve(i);
        
        vector<vector<string>> res;
        
        for(auto i : record){
            if(i.second.size() > 1){
                vector<string> tmp;
                for(auto j : i.second) tmp.push_back(j);
                res.push_back(tmp);
            }
        }
        
        return res;
        
        
    }
    
    void Solve(string path){
        int n = path.size();
        int i = 0;
        
        for(;i < n && path[i] != ' ';i++);
        string head(path.substr(0,i));
        
        while(i < n){
            if(path[i] == ' '){
                i++;
                continue;
            }
            else{
                string file_name;
                string content;
                while(i < n && path[i] != '(') file_name += path[i++];   
                i++;
                while(i < n && path[i] != ')') content += path[i++];
                i++;
                record[content].push_back(head + "/" + file_name);
            }
        }
        
        return;
        
    }
    
    
    
};
