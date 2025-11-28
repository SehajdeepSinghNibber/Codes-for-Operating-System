#include<stdio.h>
#include<pthread.h>

int data[10]={1,2,3,4,5,6,7,8,9,0};
int sum=0, max=0, min=0;

void*calc_sum(void*arg){
    sum=0;
    for ( i = 0; i < 10; i++)
    {
        sum+=data[i];
    }
    pthread_exit(NULL);
    
}

void* calc_max(void* arg) {
    max = data[0];
    for(int i = 1; i < 10; i++) {
        if(data[i] > max)
            max = data[i];
    }
    pthread_exit(NULL);
}

void* calc_min(void* arg) {
    min = data[0];
    for(int i = 1; i < 10; i++) {
        if(data[i] < min)
            min = data[i];
    }
    pthread_exit(NULL);
}

int main(){
    
    pthread_create(&t1,NULL,calc_sum,NULL);
    pthread_create(&t2,NULL,calc_max,NULL);
    pthread_create(&t3,NULL,calc_min,NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("Sum = %d\n", sum);
    printf("Maximum = %d\n", max);
    printf("Minimum = %d\n", min);

    return 0;
}