#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    struct timespec start, finish;
    clock_gettime(CLOCK_MONOTONIC, &start);

    const char *file = "testfile.txt";

    for (int i = 0; i < 4000000; i++) {
        FILE *fp = fopen(file, "r");
        fclose(fp);
    }

    clock_gettime(CLOCK_MONOTONIC, &finish);
    double total_time = (finish.tv_sec - start.tv_sec) +
                        (finish.tv_nsec - start.tv_nsec) / 1e9;
    double avg_time_per_call = total_time / 4000000.0;
    printf("Total time: %.4f seconds\n", total_time);
    printf("Average time per fork: %.9f seconds\n", avg_time_per_call);

    return 0;
}