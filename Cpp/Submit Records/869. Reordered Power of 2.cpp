/********************************************
作者:Alfeim
题目:重新排序得到2的次幂
时间消耗:1280ms
解题思路:
1.全排列法
2.枚举法
********************************************/

//全排列法
class Solution {
public:
    int n;
    unordered_set<int> validback;
    bool reorderedPowerOf2(int N) {
        
        validback.insert(2);
        validback.insert(4);
        validback.insert(6);
        validback.insert(8);  
        
        string number = to_string(N);
        n = number.size();
        
        return if2exp(number,n-1);
    }
    
    //全排列函数,最后判断是否为二的次幂只要满足 number & number - 1 = 0即可
    //因为根据位运算的性质 i & i -1 将会去除二进制位的最后一个1
    //而2的次幂一定只有一个1,所以如果取除一个1后为0,说明一定是2的次幂
    
    bool if2exp(string &number,int pos){
        
        if(pos == 0){
            if(number[0] == '0') return false;    
            int tmp = stoi(number);
            int res = tmp & (tmp - 1);
            return res == 0;
        }
        
        //用一个record记录可能重复的数字,如果已经出现过就直接跳过
        unordered_set<string> record; 
        for(int i = pos ; i >= 0 ; --i){ 
            swap(number[pos],number[i]);
            if(!record.count(number)){
                record.insert(number); 
                if(validback.count(number.back() - '0') ) if(if2exp(number,pos-1)) return true;
            }
            swap(number[pos],number[i]);
        }
        
        return false;
        
    }
       
};

//枚举法,显然更高效
//直接枚举范围内2的所有次幂,再逐个与之比较
class Solution {
public:
    bool reorderedPowerOf2(int N) {
        
        string n = to_string(N);
        sort(n.begin(), n.end());
        long tmp = 1;
        long max = 1000000000;
        while(tmp <= max){
            string str = to_string(tmp);
            sort(str.begin(), str.end()); 
            if(str.compare(n) == 0)
                return true;
            tmp = tmp << 1;
        }
        return false;
    }
};
