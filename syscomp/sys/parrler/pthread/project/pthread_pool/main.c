#include"pthread_pool.h"
void taskFunc(void*arg)
{
    int num=*(int*)arg;
    printf("thread %d is working ,tid =%ld\n",num,pthread_self());
    usleep(1000);
}
int main()
{
    threadpool*pool=threadpoolinit(3);
    for(int i=0;i<100;i++)
    {
        int*num=(int*)malloc(sizeof(int));
        *num=i;
        threadpoolAdd(pool,taskFunc,num);
    }
    sleep(3);
    threadpooldestroy(pool);
    return 0;
}