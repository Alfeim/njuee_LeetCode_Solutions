/********************************************
作者:Alfeim
题目:比较版本号
时间消耗:6ms
解题思路:用两个栈来存储两个版本号各个位置上的数值,注意
如果当前栈为空而当前数值是0,应当忽略之(相当于忽略末尾的0);
遍历完两个版本号的字串后,再分别每次比较两个栈的栈顶元素.
如果相同,就将两个栈的栈顶都弹出,继续比较;如果比较过程
因某个栈为空而结束,此时返回情况有3种:1、两个栈均空,说明
版本号相同,返回0;2、栈1为空,说明版本号1小于2,返回-1;3、
栈2为空,说明版本号2小于1,返回1;
********************************************/
class Solution {
public:
    stack<int> v1;
    stack<int> v2;
    int compareVersion(string version1, string version2) {
        for(int i = version1.size() - 1 ; i >= 0;){
            int end_pos = i,start_pos = i,tmp = 0;
           
            if(version1[i] == '.') {
                i--;
                continue;
            }
            for(; i >= 0 && version1[i] != '.' ; i--);
            start_pos = i + 1;
            string number = version1.substr(start_pos,end_pos-start_pos+1);
            tmp = stoi(number);
            if(!v1.empty() || tmp != 0) v1.push(tmp);
        }
        
       for(int i = version2.size() - 1 ; i >= 0;){
            int end_pos = i,start_pos = i,tmp = 0;
            if(version2[i] == '.') {
                i--;
                continue;
            }
            for(; i >= 0 && version2[i] != '.' ; i--);
            start_pos = i + 1;
            string number = version2.substr(start_pos,end_pos-start_pos+1);
            tmp = stoi(number);
            if(!v2.empty() || tmp != 0) v2.push(tmp);
        }
        
        while(!v1.empty() && !v2.empty()){
            int cur1 = v1.top();
            int cur2 = v2.top();               
 
            if(cur1 > cur2)
                return 1;  
            
            if(cur1 < cur2)
                return -1;

            v1.pop();
            v2.pop();
        }

        if(v1.empty() && v2.empty())
            return 0;
        return v1.empty() ? -1 : 1;
    }
};
