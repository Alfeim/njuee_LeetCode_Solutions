/********************************************
作者:Alfeim
题目:统计重复个数
时间消耗:92ms
解题思路:抽屉原理
********************************************/
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int m = s1.size(),n = s2.size();
        int sum = 0,counter = 1,pos = 0;
        vector<int> Cnt(n1 + 1,0);
        vector<int> next(n1 + 1,0);
        while(counter <= n1){
            for(int i = 0 ; i < m ; i++){
                if(s1[i] == s2[pos]){
                    if(pos == n - 1){
                        pos = 0;
                        sum++;
                    }else
                        pos++;
                }
            }
            
            Cnt[counter] = sum;
            next[counter] = pos;
            for(int begin = 0 ; begin < counter ; ++begin){
                if(next[begin] == pos){
                    int interval = counter - begin;
                    int N = (n1 - begin)/interval;
                    int intervalCNT = N * (Cnt[counter] - Cnt[begin]);
                    int leftCNT = Cnt[begin + (n1 - begin)%interval];
                    return (intervalCNT + leftCNT)/n2;
                }
            }
            counter++;
        }
        return Cnt[n1] / n2;
    }
};
        
