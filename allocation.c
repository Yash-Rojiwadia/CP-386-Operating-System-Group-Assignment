#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/stat.h>
#include <time.h>
#include <semaphore.h>
#include <stdbool.h>

typedef struct p
{
    char command;
    int size;
    int start;
    int end;
} Process;

int main(int argc, char *argv[]) {
    int input;
    input = atoi(argv[1]);
}

