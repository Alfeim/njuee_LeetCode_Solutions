/********************************************
作者:Alfeim
题目:第N个神奇数字
时间消耗:4ms
解题思路:二分搜索
********************************************/
class Solution {
public:
    long long MCM;
    long long mod;
    int nthMagicalNumber(int N, int A, int B) {
        if(A == 0 || B == 0) return 0;
        if(A == 1 || B == 1) return N;
        
        mod = 1000000007;
        MCM = (long long)(A * B)/(long long)Gcd(A,B); 
    
        int ans = Solve(1,N,N,A,B);
        if( ans != -1) return ans;
        
        return Solve(1,N,N,B,A);
        
         
    }
    
    int Solve(long long low,long long high,long long N,long long A,long long B){
        
        if(low >= high){
            long long count = low + (low*A/B) - (low*A/MCM);
            if(count == N) return (low * A + mod)%mod;
            
            return -1;
        }
            
        //mid表示当前A的个数
        long long mid = (low + high)>>1;
        
        //实际的数量 = A的个数 + B的个数 - A和B的最小公倍数的个数
        long long count = mid + (mid*A/B) - (mid*A/MCM);
        
        if(count == N) return (mid*A + mod)%mod;
        
        if(count < N ) return Solve(mid+1,high,N,A,B);
        
        return Solve(low,mid-1,N,A,B);
        
        
    }
    
    //求最小公倍数
    int Gcd(int a,int b){
        while(b){
            int tmp = a%b;
            a = b;
            b = tmp;
        }
        
        return a;
    }
    
};
