/********************************************
作者:Alfeim
题目:交替打印字符串
时间消耗:16ms
解题思路:互斥锁
********************************************/
class FizzBuzz {
private:
    int n;
    int tmp;
    mutex M,M3,M5,M35;
public:
    FizzBuzz(int n):tmp(1){
        this->n = n;
        M3.lock();
        M5.lock();
        M35.lock();
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        int count3 = n/3 - n/15;
        for(int i = 0 ; i < count3 ; ++i){
            M3.lock();
            printFizz();
            tmp++;
            if(tmp % 3 != 0 && tmp % 5 != 0) 
                M.unlock();
            else if(tmp%15 == 0){
                M35.unlock();
            }else if(tmp%3 == 0){
                M3.unlock();
            }else if(tmp%5 == 0){
                M5.unlock();
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        int count5 = n/5 - n/15;
        for(int i = 0 ; i < count5 ; ++i){
            M5.lock();
            printBuzz();
            tmp++;
            M.unlock();
            if(tmp % 3 != 0 && tmp % 5 != 0) 
                M.unlock();
            else if(tmp%15 == 0){
                M35.unlock();
            }else if(tmp%3 == 0){
                M3.unlock();
            }else if(tmp%5 == 0){
                M5.unlock();
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        int count35 = n/15;
        for(int i = 0 ; i < count35 ; ++i){
            M35.lock();
            printFizzBuzz();
            tmp++;
            if(tmp % 3 != 0 && tmp % 5 != 0) 
                M.unlock();
            else if(tmp%15 == 0){
                M35.unlock();
            }else if(tmp%3 == 0){
                M3.unlock();
            }else if(tmp%5 == 0){
                M5.unlock();
            }
        }    
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        int count = n - n/3 - n/5 + n/15;
        for(int i = 0 ; i < count ; ++i){
            M.lock();
            printNumber(tmp);
            tmp++;

            if(tmp%15 == 0){
                M35.unlock();
            }else if(tmp%3 == 0){
                M3.unlock();
            }else if(tmp%5 == 0){
                M5.unlock();
            }else{
                M.unlock();
            }

        }
    }
};
