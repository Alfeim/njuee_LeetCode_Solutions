/********************************************
作者:Alfeim
题目:最大单词长度乘积
时间消耗:52ms
解题思路:因为只有26个字母,可以用一个int类型的变量
表示某个单词中是否有某个字母，比如其0位对应字母a,
1位对应字母b...判断两个单词是否有重复字母，只需要
将两个单词对应的整形相与,如果结果为0说明不重复
********************************************/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int size=words.size();
        vector<int> bit_value(size,0);
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                bit_value[i] |= 1<<(words[i][j]-'a');
            } 
        }
        int tmp,result=0;
        for(int i=0;i<size;i++)
        {
            for(int j=i+1;j<size;j++)
            {
                if (!(bit_value[i]&bit_value[j]))
                {
                    tmp = words[i].size()*words[j].size();
                    result = tmp>result?tmp:result;
                }
            }
        }
        return result;
    }
};
