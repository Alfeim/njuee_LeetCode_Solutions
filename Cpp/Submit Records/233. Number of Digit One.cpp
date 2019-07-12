/********************************************
作者:Alfeim
题目:数字1的个数
时间消耗:4ms
解题思路:递归;
把n拆分为两个部分，即 高位到次高位 和 次高为以下的部分,比如34567，可以拆分成4567-34567和4567以下;
每次都计算从次高位到高位的中的"1"的个数。 比如4567-34567,我们可以先固定最高位(万位),其中最高为是"1"
的个数显而易见,即从10000-19999万位都是1，所以最高为数目是10^4;而如果最高位原本就是1呢?比如我们把
34567变成14567，那么最高位为1的数目就是 14567 - 10000 + 1 ,也就是次高位之后的数字 + 1; 在计算完最
高位的1的个数后,我们可以很容易得到剩余位置上的1的个数,比如前例,除了万位外，我们如果把任意一位置1，都
有10^3种组合，一共有4位可以置1，所以有4*10^3种组合，而万位为3,显然则一共有3*4*10^3种组合了。
接下来，只需要递归计算次高位之下的数即可
********************************************/
class Solution {
public:
    int countDigitOne(int n) {
        if( n <= 0)
            return 0;
        
        string Number = to_string(n);
        return Solve(Number);
    }
    int Solve(string Number){
        if(Number.empty())
            return 0;
        
        int first_number = Number[0] - '0';
        if(first_number == 0 && Number.size() == 1)
            return 0;
        if(first_number > 0 && Number.size() == 1 )
            return 1;
        
        int sum1 = 0;
        if(first_number > 1)
            sum1 = pow(10,Number.size()-1);
        else if(first_number == 1)
            sum1 = stoi(Number.substr(1)) + 1;
        int sum2 = first_number * (Number.size() - 1)*pow(10,Number.size()-2);
        return sum1 + sum2 + Solve(Number.substr(1));
    }
    
};
