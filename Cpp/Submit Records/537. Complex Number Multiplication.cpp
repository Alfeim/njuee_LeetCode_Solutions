/********************************************
作者:Alfeim
题目:复数乘法
时间消耗:4ms
解题思路:..没啥好说
********************************************/
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int L1 = 0 ,L2 = 0 ,R1 = 0,R2 = 0;
        
        int m = a.size(),n = b.size();
        
        for(int i = 0 ; i < m ;){
            string left;
            while(i < m && a[i] != '+') left += a[i],i++;
            L1 = stoi(left);
            
            i++;
            string right;
            while(i < m && a[i] != 'i') right += a[i],i++;
            R1 = stoi(right);
            
            break;
        }
      
        for(int i = 0 ; i < n ;){
            string left;
            while(i < n && b[i] != '+') left += b[i],i++;
            L2 = stoi(left);
            
            i++;
            string right;
            while(i < n && b[i] != 'i') right += b[i],i++;
            R2 = stoi(right);
            
            break;
        }
        
        
        int ResL = L1*L2 - R1*R2;
        int ResR = L1*R2 + L2*R1;
        
        return to_string(ResL) + "+" + to_string(ResR) + "i";
    }
};
