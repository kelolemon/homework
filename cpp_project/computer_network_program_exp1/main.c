# include <stdio.h>
# include <pthread.h>
//数据类型：

int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr); //对一个互斥量进行初始化
int pthread_mutex_destroy(pthread_mutex_t *mutex); //销毁一个互斥量返回值：成功则返回0，否则返回错误编号
int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_trylock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);
// 返回值：成功则返回0，否则返回错误编号
// 这三个函数用于对互斥量进行加锁解锁。其中pthread_mutex_trylock是非阻塞的加锁函数，若加锁失败，则立即返回EBUSY。


#include<pthread.h>

// 数据类型：
pthread_t pthread; // 线程ID
pthread_t pthread_self(); //返回调用线程的线程ID
int pthread_create(pthread_t *tidp, const pthread_attr_t attr, void *(*start_rtn)(void*), void *arg);
// 线程创建函数，tidp，用于返回线程ID；attr，线程属性，若设为NULL,则线程使用默认属性； start_rtn是线程例程函数，arg为线程函数参数。


int main() {
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_lock(&mutex);
    pthread_mutex_unlock(&mutex);
    pthread_mutex_destroy(&mutex);
    printf("Hello, World!\n");
    return 0;
}