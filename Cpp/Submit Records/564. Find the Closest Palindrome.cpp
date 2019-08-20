/********************************************
作者:Alfeim
题目:寻找最近的回文数
时间消耗:0ms
解题思路:最近的回文数一定就是下列三种情况之一：
1、中间数字不变,左右镜像
2、中间数的数-1,左右镜像
3、中间数+1,左右镜像
********************************************/
class Solution {
public:
    string nearestPalindromic(string n) {
        if(n.size() == 1)
            return to_string(stoi(n) - 1);
        
        string add(add_one(n));
        string minus(minus_one(n));
        string raw(n);
        
        long number1 = stol(Palindrome(add));
        long number2 = stol(Palindrome(minus));
        long number3 = stol(Palindrome(raw));
        long N = stol(n);
        
        
        long diff1 = abs(number1 - N);
        long diff2 = abs(number2 - N);
        long diff3 = abs(number3 - N);
        
        map<long,long> record;
        
        if(diff1 != 0) 
            record[diff1] = number1;
        
        if(diff2 != 0){
            if(record.count(diff2) == 0)
                record[diff2] = number2;
            else{
                record[diff2] = min(number2,record[diff2]);
            }
        }
        
        if(diff3 != 0){
            if(record.count(diff3) == 0)
                record[diff3] = number3;
            else{
                record[diff3] = min(number3,record[diff3]);
            }
        }
        
        
        long ans = (record.begin())->second;
        return to_string(ans);
    }
    
    string add_one(string str){
        int n = str.size();
        int mid = (n - 1)/2;
        string left_part = str.substr(0,mid+1);
        int left_number = stoi(left_part);
        left_number += 1;
        return to_string(left_number) + str.substr(mid+1);
    }
    
    string minus_one(string str){
        int n = str.size();
        int mid = (n - 1)/2;
        for(int i = mid ; i >= 0 ; --i){
            if(str[i] == '0')
                str[i] = '9';
            else{
                str[i] -= 1;
                break;
            }
        }
        
        if(str[0] == '0'){
            return "9" + str.substr(1,n-2);
        }
        return str;
    }
    
    string Palindrome(string str){
        int n = str.size();
        for(int i = 0 , j = n - 1; i < j ; i++,j--) str[j] = str[i];
        return str;
    }

};
