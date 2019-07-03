/********************************************
作者:Alfeim
题目:复原ip地址
时间消耗:8ms
解题思路:递归、边界处理
********************************************/
class Solution {
public:
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        if(s.size() < 4 || s.size() > 12)
            return res;
        
        string tmp;
        Solve(s,0,tmp,1);
        return res;
    }
    void Solve(string s,int begin,string tmp,int count){
        if(count == 4){
            if(s.size() - begin <= 3){
                long number = stol(s.substr(begin));   
                if((s[begin] != '0' && number > 0 && number <= 255) || (s[begin] == '0' && begin == s.size()-1) ){
                    tmp += s.substr(begin);
                    res.push_back(tmp);
                }
            }
            return;
        }   
        for(int i = begin ; i < s.size() && i < (begin + 3 ) ;++i){
            long c = stol(s.substr(begin,i - begin + 1));
            if( c == 0 && i< s.size() - 1){
                Solve(s,i+1,tmp + "0.",count+1);
                break;
            }else if( c > 0 && c <= 255 && i < s.size() - 1){
                string newtmp(tmp + to_string(c) + '.');
                Solve(s,i+1,newtmp,count+1);
            }  
        }
    }
 
};
