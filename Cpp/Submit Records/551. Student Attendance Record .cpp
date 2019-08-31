/********************************************
作者:Alfeim
题目:学生出勤记录1
时间消耗:4ms
解题思路:没啥好说的..
********************************************/
class Solution {
public:
    bool checkRecord(string s) {
        int Acount = 0;
        int Lcount = 0;
        int n = s.size();
        for(int i = 0 ; i < n ; ++i){
            if(s[i] == 'L'){
                Lcount++;
                if(Lcount > 2) return false;
            }else{
                Lcount = 0;
                if(s[i] == 'A'){
                    Acount++;
                    if(Acount > 1) return false;
                }
            }
        }
        
        return true;
    }
};
