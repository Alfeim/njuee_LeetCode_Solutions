/********************************************
作者:Alfeim
题目:推倒多米诺
时间消耗:44ms
解题思路:记录每个'.'位置 左边最近的R的距离 和右边最近的 L的距离; 
推倒后 该位置如果离R比较近就是R，离L比较近就是L，否则不变
********************************************/
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        if(n <= 1) return dominoes;
        
        vector<int> R_pos(n,-1);
        vector<int> L_pos(n,n);
        
        int left = n ,right = -1;
        
        for(int i = 0 ; i < n ; ++i){
            if(dominoes[i] == 'R') right = i;
            else if(dominoes[i] == '.') R_pos[i] = right;
            else right = -1;
        }
        
        for(int i = n - 1 ; i >= 0 ; --i){
            if(dominoes[i] == 'L') left = i;
            else if(dominoes[i] == '.') L_pos[i] = left;
            else left = n;
        }
        
        for(int i = 0 ; i < n ; ++i){
            if(dominoes[i] == '.'){
                if(R_pos[i] < 0 && L_pos[i] >= n) 
                    continue;
                
                if(R_pos[i] < 0){
                    dominoes[i] = 'L';
                }else if(L_pos[i] >= n){
                    dominoes[i] = 'R';
                }else{
                    if(abs(i - R_pos[i]) > abs(i - L_pos[i])) dominoes[i] = 'L';
                    else if(abs(i - R_pos[i]) < abs(i - L_pos[i])) dominoes[i] = 'R';
                }
            }
        }
        
        return dominoes;
        
    }
};
