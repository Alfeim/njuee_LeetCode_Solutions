/********************************************
作者:Alfeim
题目:不含AAA或者BBB的字符串
时间消耗:0ms
解题思路:贪心算法
********************************************/
class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string res;

        while(A > 0 || B > 0){
            bool flag = false;
            
            int n = res.size();
            
            if(n >= 2 && res[n-1] == res[n-2] ){
                if(res[n-1] == 'b') flag = true;
            }else{
                if(A >= B) flag = true;
            }
            
            if(flag){
                res += 'a';
                A--;
            }else{
                res += 'b';
                B--;
            }
            
        }
          
        return res;
    }
    
};
