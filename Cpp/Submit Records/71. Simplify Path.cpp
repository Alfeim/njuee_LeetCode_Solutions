
/********************************************
作者:Alfeim
题目:搜索二维矩阵
时间消耗:12ms
解题思路:用双向数组或者栈,遍历原字串,如果遇到..则将容器顶部的元素弹出
********************************************/
class Solution {
public:
    deque<string> res;
    string ans;
    string simplifyPath(string path) {
       for(int i = 0 ; i < path.size();){
           if(path[i] == '/')
               i++;
           else{
               string tmp;
               for(;i < path.size() && path[i] != '/';++i)
                   tmp += path[i];   
               if(tmp == ".")
                   continue;
               else if(tmp == ".."){
                   if(!res.empty()) res.pop_back();
               }else{
                   res.push_back(tmp);
               }

           }  
       }    
       if(res.empty())
           return "/";

       while(!res.empty()){
           ans += '/' + res.front();
           res.pop_front();
       } 
        return ans; 
    }
};


