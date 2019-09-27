/********************************************
作者:Alfeim
题目:计数二进制字串
时间消耗:4ms
解题思路:用两个变量维护性质即可
********************************************/
class Solution {
public:
    int countBinarySubstrings(string s) {
        int count_zero = 0;
        int count_one  = 0;
        int res = 0;
        int n = s.size();
        
        for(int i = 0 ; i < n ;){
            
            if(s[i] == '0'){
                if(count_one == 0){
                    count_zero++;
                    i++;
                }else{
                    while(i < n && s[i] == '0'){
                        count_zero++;
                        i++;
                    }
                    res += min(count_one,count_zero);
                    count_one = 0;
                }
            }else{
                if(count_zero == 0){
                    count_one++;
                    i++;
                }else{
                    while(i < n && s[i] == '1'){
                        count_one++;
                        i++;
                    }
                    res += min(count_one,count_zero);
                    count_zero = 0;
                }
            }
        }
        
        return res;
        
    }
};

