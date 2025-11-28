#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int shared=0;
sem_t mutex;

void* thread1_func(void* arg){
    for (int i = 0; i < 100000; i++) {
        sem_wait(&mutex);
        shared++;
        sem_post(&mutex);
    }
        pthread_exit(NULL);
}

void* thread2_func(void* arg){
    for (int i = 0; i < 100000; i++) {
        sem_wait(&mutex);
        shared++;
        sem_post(&mutex);
    }
        pthread_exit(NULL);

}

int main(){

    pthread_t t1,t2;

    sem_init(&mutex,0,1);

    pthread_create(&t1,NULL,thread1_func,NULL);
    pthread_create(&t2,NULL,thread2_func,NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&mutex);

    printf("%d",shared);

    return 0;
}