/********************************************
作者:Alfeim
题目:第N个数字
时间消耗:4ms
解题思路:递归
********************************************/
class Solution {
public:
    int findNthDigit(int n) {
        int i =1;      
        while(n>i*(pow(10,i-1))*9)
        {
            n-=i*(pow(10,i-1))*9;  
            i++;                   
        }
        int am_num=(n-1)/i+pow(10,i-1);  
        string a=to_string(am_num);      
        if(n%i==0)
            return (a[i-1]-'0');   
        return (a[n%i-1]-'0');     
    }
};
