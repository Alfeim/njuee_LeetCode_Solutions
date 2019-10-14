/********************************************
作者:Alfeim
题目:有序队列
时间消耗:8ms
解题思路:

我们可以看出：如果K = 1,相当于是个环形队列，只需要遍历每一个位置寻找字典序最小的即可

如果K >= 2,我们都可以实现两个相邻位置的“互换”,也就意味着可以冒泡排序,所以字典序最小的就是排序后的结果

********************************************/
class Solution {
public:
    int n;
    string orderlyQueue(string S, int K) {
        n = S.size();
        
        if(K == 0) return S;
        
        if(K == 1){
            string MinStr(n,'z');
            for(int i = 0 ; i < n ; ++i){
                string cur =  S.substr(i) + S.substr(0,i);
                if(isless(cur,MinStr)) MinStr = cur;
            }
            
            return MinStr;
        }
        
        sort(S.begin(),S.end());
        return S;
        
    }
    
    bool isless(const string &str1,const string &str2){
        
        for(int i = 0 ; i < n ; ++i){
            if(str1[i] < str2[i]) return true;
            else if(str1[i] > str2[i]) return false;
        }
        
        return false;
    }
};
