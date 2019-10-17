/********************************************
作者:Alfeim
题目:宝石与石头
时间消耗:4ms
解题思路:用两个变量记录大写字母和小写字母哪些“位置”是“宝石”即可
********************************************/
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int standard1 = 0;
        int standard2 = 0;
        int res = 0;
        
        for(auto i : J ){
            if(islower(i)) standard1 |= (1<<(i-'a'));
            else standard2 |= (1<<(i-'A'));
        }
        
        for(auto i : S){
            if(islower(i)){
                if( ( standard1 >> (i - 'a') ) & 1 == 1) res++;
            }else{
                if( ( standard2 >> (i - 'A') ) & 1 == 1) res++;
                
            }
        }
        
        return res;
        
        
    }
};
