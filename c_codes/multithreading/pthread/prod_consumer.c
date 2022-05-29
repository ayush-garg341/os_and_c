#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


pthread_cond_t empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t fill = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

int loops = 10000;
int MAX = 1000;
int count = 0;

void *producer(void *arg){
    while(count <= MAX){
        pthread_mutex_lock(&mutex1);
        while(count == MAX){
            /* go to sleep as queue is full and awaken as soon as element gets consumed */
            pthread_cond_wait(&empty, &mutex1);
        }
        put(args); // put/produce an item in queue
        pthread_cond_signal(&fill);
        pthread_mutex_unlock(&mutex1);
    }
}


void *consumer(void *arg){
    while(count <= MAX){
        pthread_mutex_lock(&mutex1);
        while(count == 0){
            /* go to sleep as queue is empty and awaken as soon as it gets filled */
            pthread_cond_wait(&fill, &mutex1);
        }
        get(); // get/consumes an item
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex1);
    }
}


int main(int argc, char* argv[]){
    producer(); // produce the items in queue
}
