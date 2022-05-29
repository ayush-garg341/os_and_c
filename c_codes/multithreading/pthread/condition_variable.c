#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int done = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c = PTHREAD_COND_INITIALIZER;

void thr_exit(){
    /* Lock must be held while calling wait and signal with CV */
    pthread_mutex_lock(&m);
    done = 1;
    pthread_cond_signal(&c);
    pthread_mutex_unlock(&m);
}

void* child(){
    printf("Child: begin\n");
    thr_exit();
    return NULL;
}


void thr_join(){
    /* this ops should happen atomically*/
    pthread_mutex_lock(&m);
    while(done==0){
        pthread_cond_wait(&c, &m);
    }
    pthread_mutex_unlock(&m);
}

int main(int arg, char *argv[]){
    printf("Parent: begin\n");
    pthread_t p;
    pthread_create(&p, NULL, child, NULL);
    thr_join();
    printf("Parent: end\n");
    return 0;
}
