#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/stat.h>
#include <time.h>
#include <semaphore.h>
#include <stdbool.h>

# define MAX 10

typedef struct p
{
    char command;
    int size;
    int start;
    int end;
} Process;

int insert_process (Process *all_process[], Process *full_process[], char *process, int process_size, int index){
    int i = 0;
    while (i < MAX){
        if (full_process[i] != NULL && strcmp(full_process[i],process)){
            
        }
        i++;
    }
}

int main(int argc, char *argv[]) {
    int input;
    input = atoi(argv[1]);
}

