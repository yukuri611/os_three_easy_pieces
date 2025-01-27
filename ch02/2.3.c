#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>


int main(int argc, char *argv[]) {
    int *p = malloc(sizeof(int));

    printf("(%d) address of p: %08x\n", getpid(), (unsigned) p);

    *p = 0;
    while(1) {
        Spin(1);
        *p = *p + 1;
        printf("(%d) value of p: %d\n", getpid(), *p);
    }
    return 0;
}

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