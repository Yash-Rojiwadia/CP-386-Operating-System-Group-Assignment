#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

# define MAX 10

const char *rq = "RQ";
const char *rl = "RL";
const char *c = "C";
const char *status = "STATUS";
const char *exit = "EXIT";

typedef struct p
{
    char command[10];
    char number_p[3];
    int size;
    int start;
    int end;
    
} Process;

typedef struct h
{
    int holes;
    int partitions;

} Holes;

int allocate_mem (){
   
    }


int main(int argc, char *argv[]) {
    char input;
    input = atoi(argv[1]);
    Process *p = NULL;
    Holes *h = NULL;

    printf("Allocated %d bytes of memory.\n", input);


    printf("command>");

    

   
    
}

