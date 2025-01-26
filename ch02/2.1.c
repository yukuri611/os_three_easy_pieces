#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s <value>\n", argv[0]);
        exit(1);
    }

    char *str = argv[1];
    while(1) {
        printf("%c\n", *str);
        Spin(1);
    }
}

void Spin(int time){
    struct timeval start, end;
    gettimeofday(&start, NULL);
    while(1) {
        gettimeofday(&end, NULL);
        if ((end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec) > time * 1000000) {
            break;
        }
    }
}