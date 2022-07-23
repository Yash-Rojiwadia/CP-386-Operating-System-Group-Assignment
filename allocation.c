#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>


const char *rq = "RQ";
const char *rl = "RL";
const char *c = "C";
const char *status = "STATUS";
//const char *exit = "EXIT";

typedef struct p
{
    char command[10];
    int size;
    int start;
    int end;
    
} Process;

typedef struct allocation
{
    char command[10];
    char p_letter[3];
    int p_number;
    long mem;
    char algo;
    int f_index;
    int l_index;
    int length;
} Allocation;


typedef struct h
{
    int holes;
    int partitions;

} Holes;



// char** inputstr(char * userinput){
//     size_t i = 0;
//     char *str_array[] = {};
//     for (int j=0;j<3;j++){
//         char * str_temp = "" ;
//         char * strtemp2 = "";
//         while (userinput[i] != '\0' && isspace(userinput[i]) ) {       /* Stop looping when we reach the null-character. */
//             strcat(str_temp,itoa(i,strtemp2,10));
//             //printf("%c\n", userinput[i]);    /* Print each character of the string. */
//             i++;
//         }
//         strcat(str_array, str_temp);
//     }
//     return str_array;
// }
Process *p = NULL;
Holes *h = NULL;

void main(int argc, char *argv[]) {
   
    char input = argv[1];
    Allocation aloc;
    char *ptr;
    int num = strtol(input,&ptr,10);
    printf("Allocated %d bytes of memory.\n", num);

    //char ** temp = inputstr("RQ P3 1200000 B");
    //printf("results : %s",temp) ;
    //printf("\n");
   

    //get user input
    char another_inp[] = {}; 
    do {
        
        printf("command>");

        //read until usr presses enter
        char *line = NULL;
        size_t len = 0;
        ssize_t linesize = 0;
        linesize = getline(&line, &len, stdin);
        char *token;
        token = strtok(&line, " ");
        int j = 0;

        while (token != NULL){
            if (j == 0){
                strcpy(aloc.command, token);
                
            }else if (j == 1){
                strcpy(aloc.p_letter, token);
               
                aloc.p_number = (int) aloc.p_number;
            }else if (j == 2){
                aloc.mem = (int) atoi(token);
            }else if(j == 3){
                strcpy(aloc.algo, token); 
                  
            }
            j++;
            token = strtok(NULL, " ");  
        }

    }while (1);

    int table_memory [num];
    int i = 0;
    while (i<num){
        table_memory[i] = -1 ;
    }

}