/********************************************
作者:Alfeim
题目:超级次方
时间消耗:40ms
解题思路:数学
********************************************/
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        //当b为个位数时
        if(b.size() == 1){
            return Solve(a,b[0]);
        }
        //否则,拆分成两部分,以让b每次左移一位
        vector<int> tmp;
        tmp.push_back(b.back());
        //part1是b的最后一位,如果为0则让其为1,否则求出该余数
        int part1 = b.back() == 0 ? 1 : superPow(a,tmp);
        b.pop_back();
        //另一部分是求a^10b%1337，可以看做是(a^b)^10%1337 = (superPower(a,b)^10)%1337;
        int tmp2 = superPow(a,b);
        int part2 = Solve(tmp2,10);
        return (part1 * part2)%1337;
    }
    
    int Solve(int a,int exp){
            long res = 1;
            while(exp > 0){
                res *= a ;
                res = res % 1337;
                exp -= 1;
            }
            return res;
    }
};
