/********************************************
作者:Alfeim
题目:交替打印FooBar
时间消耗:84ms
解题思路:并发编程、条件变量的使用//也可以直接用两个锁
********************************************/
class FooBar {
private:
    int n;
    bool Ready1;
    bool Ready2;
    std::mutex readyMutex1,readyMutex2;
    std::condition_variable readyConvar1,readyConvar2;
public:
    FooBar(int n){
        this->n = n;
        Ready1 = true;
        Ready2 = false;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> ul(readyMutex1);
            readyConvar1.wait(ul,[this]{return Ready1;});
            // printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            
            Ready1 = false;
            Ready2 = true;
            
            readyConvar2.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> ul(readyMutex2);
            readyConvar2.wait(ul,[this]{return Ready2;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            
            Ready1 = true;
            Ready2 = false;
            
            readyConvar1.notify_one();
           
        }
    }
};
