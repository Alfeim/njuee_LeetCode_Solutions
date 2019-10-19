/********************************************
作者:Alfeim
题目:H2O生成
时间消耗:112ms
解题思路:互斥锁、信号量
********************************************/

//信号量做法
#include <semaphore.h>
class H2O {
public:
    sem_t Hyd;
    sem_t Oxy;
    int count_H;
    H2O():count_H(0){
        sem_init(&Hyd,0,2);
        sem_init(&Oxy,0,1);
    }

    void hydrogen(function<void()> releaseHydrogen) {
        sem_wait(&Hyd);
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        count_H++;
        if(count_H == 2){
            count_H = 0;
            sem_post(&Oxy);
        }
        
    }
    
    
    void oxygen(function<void()> releaseOxygen) {
        sem_wait(&Oxy);
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        sem_post(&Hyd);
        sem_post(&Hyd);
    }
};



//互斥锁做法
class H2O {
public:
    std::mutex MH,MO;
    int counth;
    H2O():counth(0){
       MO.lock();
    }

    void hydrogen(function<void()> releaseHydrogen) {
        MH.lock();
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        
        counth++;
        
        if(counth == 1){
            MH.unlock();
        }
        
        if(counth == 2){
            counth = 0;
            MO.unlock();
        }
        
    }

    void oxygen(function<void()> releaseOxygen) {
        MO.lock();
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        MH.unlock();
    }
};
