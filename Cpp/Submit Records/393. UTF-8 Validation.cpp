/********************************************
作者:Alfeim
题目:UTF-8验证
时间消耗:12ms
解题思路:递归
********************************************/
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        if(data.empty())
            return true;
        
        return Solve(data,0);
    }
    
    bool Solve(vector<int> &data,int pos){
        int n = data.size();
        if(pos >= n)
            return true; 
        //先根据第一位来判断长度
        int first_byte = data[pos] & 0xff;
        //如果第一位的首位是0,说明是长度为1的字节,则继续判断
        if(first_byte >> 7 == 0) return Solve(data,pos + 1);
        
        //否则,从长度为2开始遍历
        for(int m = 2 ; m <= 4 ; ++m){
            //长度为m的UTF8编码,首字节的m+1位是2的m+1次方减2;
            int cur_byte = pow(2,m+1) - 2;
            //如果遇到匹配的首字节头,则判断后续的m个字节
            if( first_byte >> (7-m) == cur_byte  &&   n - pos + 1 >= m ){
                for(int i = 1 ; i < m; ++i){
                    int tmp = data[pos + i] & 0xff;
                    tmp >>= 6;
                    if(tmp != 2)
                    return false;
                }
            return Solve(data,pos + m);
            }
        }
        
        return false;
        
    }
    
};
