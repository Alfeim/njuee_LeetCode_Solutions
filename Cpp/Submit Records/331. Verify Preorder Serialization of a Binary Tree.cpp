/********************************************
作者:Alfeim
题目:验证二叉树的前序序列化
时间消耗:4ms
解题思路:从序列起始处开始遍历,如果遇到数值就入栈，
如果遇到"#"号,说明该位置已经到达了叶子节点,这时候
需要查看栈顶是否也为"#",如果是,说明栈顶的前一位置
就是该叶子节点的父节点.因此我们将栈顶元素和栈顶的
上一元素出栈,然后用"#"替代(入栈,表示某一分支已经
结束),这样操作后,最终根节点的左右孩子都会被替代为
"#"，合并后栈中只剩下一个"#"，表明所有节点都已经
遍历完。如果最后栈中大小不为1，说明该序列是错误的
********************************************/
class Solution {
public:
    stack<char> S;
    bool isValidSerialization(string preorder) {
        if(preorder.size() == 1)
            return preorder[0] == '#';
        
        for(int i = 0 ; i < preorder.size();){
            if( preorder[i] == ',') {
                i++;
                continue;
            }
            string tmp;
            while(i < preorder.size() && preorder[i] != ',') tmp += preorder[i++];
            if(S.size() == 1 && S.top() == '#')
                return false;
            
            if(tmp != "#")
                S.push('a');
            else
            {
                while(S.size() >= 2 && S.top() == '#'){
                    S.pop();
                    S.pop();
                }
                S.push('#');
            } 
        }
        
        return S.size() == 1;
    }
};
