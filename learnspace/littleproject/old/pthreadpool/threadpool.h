#pragma once
#include "TaskQueue.h"
#include"taskqueue.cpp"
template<class T>
class threadpool
{
private:
    TaskQueue<T> *Taskq;
    pthread_t managerid;      //管理者线程id
    pthread_t *threadid;      //工作的线程id
    int minNum;               //最小线程数量
    int maxNum;               //最大的线程数
    int busyNum;              //工作中的线程数量
    int liveNum;              //存活的线程的个数
    int exitNum;              //要销毁的线程的个数
    pthread_mutex_t mutepool; //锁整个线程池
    pthread_cond_t notempty;  // 任务队列是不是空了
    bool shutdown;            //是不是要销毁，1是销毁，0不销毁
    static const int NUMBRE = 2;

public:
    threadpool(int min, int max);
    ~threadpool();
    void addTask(task<T> task);
    int getBusyNum(); // 查看工作中的线程数量
    int getliveNum(); //查看存活的线程数量

private:
    static void *worker(void *arg);
    static void *manger(void *arg);
    void threadexit();
};
