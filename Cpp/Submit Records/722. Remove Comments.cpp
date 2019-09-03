/********************************************
作者:Alfeim
题目:删除注释
时间消耗:8ms
解题思路:细节题
********************************************/
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        bool flag = false; //表示块注释的标记
        vector<string> res;
        string tmp;
        for(auto i : source){
            int n = i.size();
            if(!flag) tmp.clear();               //如果当前不在注释块范围内,重置临时字符串    
            for(int pos = 0 ; pos < n ; ++pos){  //遍历当前区域
                if(i[pos] != '/' && !flag){      //如果当前不在注释块范围且是正常字符,就直接将之写入临时字符串
                    
                    tmp += i[pos];
                    
                }else if(i[pos] == '/' && !flag){ //如果当前不再注释块范围且是'/'字符,需要分三种情况
                    
                    if(pos < n - 1 && i[pos + 1] == '/') {     //情况1,如果下个字符也是'/'就直接跳出当前循环(因为整行都被注释了)
                        break;
                    }else if(pos < n - 1 && i[pos+1] == '*'){  //情况2,如果下个字符是'*'意味着接下来是被块注释了,将flag置为真
                        pos++;
                        flag = true;
                    }else{                                     //否则就是正常的'/'符号
                        tmp += i[pos];
                    }
                    
                }else if(pos < n - 1 && i[pos] == '*' && i[pos+1] == '/' && flag) {  //如果当前还在注释快区域,但是遇到了"*/"就将flag置为false
                    
                    pos++;
                    flag = false;
                    
                }
            }
            if(!tmp.empty() && !flag) res.push_back(tmp);  //如果当前不再注释块范围内就将临时字符串压入res
        }
        return res;
    }
};
