#include<stdio.h>
#include<sys/time.h>

/*struct timeval{*/
    /*time_t tv_sec; // seconds since Jan 1, 1970*/
    /*suseconds_t tv_usec; // microseconds*/
/*};*/

int main(){
    struct timeval now;
    gettimeofday(&now, NULL);
    double secsSinceEpoch = now.tv_sec + now.tv_usec / 1000000.0;
    printf("%lf\n", secsSinceEpoch);
    return 0;
}
