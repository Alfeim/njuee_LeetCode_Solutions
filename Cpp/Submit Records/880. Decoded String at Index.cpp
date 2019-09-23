/********************************************
作者:Alfeim
题目:索引处的解码字符串
时间消耗:4ms
解题思路:

我们用size表示当前解码字符串的长度
先正序遍历一次算出总长度

然后让i从S末尾开始倒序遍历

每次更新K的位置为 ： K % size(因为先前字符串重复了,所以去重后实际位置变成了对当前size取余)

如果K = 0,且当前非数字 返回S[i]

然后更新size：

如果遇到数字,size /= number
如果遇到字母 size -= 1;



********************************************/
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long long size = 0;
        int n = S.size();
        for(int i = 0; i < n ; ++i){
            if(isalpha(S[i])) size++;
            else size *= (S[i] - '0');
        }
        
        for(int i = n - 1 ; i >= 0 ; --i){
            K %= size;
            
            if(K == 0 && isalpha(S[i]))
                return string(1,S[i]);
            
            if(isdigit(S[i]))
                size /= (S[i] - '0');
            else 
                size--;
            
        }

        return "";
    
    }
    
};
