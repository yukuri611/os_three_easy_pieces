#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void Spin(int time) {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    while(1) {
        gettimeofday(&end, NULL);
        if ((end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec) > time * 1000000) {
            break;
        }
    }
}