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
const char *first = "F";
const char *best = "B"; 
const char *worst = "W"; 
//const char *exit = "EXIT";



typedef struct p
{
    char command[10];
    int size;
    int start;
    int end;
    
} Process;

Process *p = NULL;
Process *p1 = NULL;

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

int alloc; 
int total_a_count;
int a_count;



static void empty_stat(int *table_memory,int num){
    int counter = 0;

    for (int i = 0; i < num ; i++){
        if (table_memory[i] == -1){
            p1[total_a_count].start = i;

            while (table_memory[i] == -1){
                counter ++;
                i++;
            }
            p1[total_a_count].end = i-1 ;
            p1[total_a_count].size = p1[total_a_count].end - p1[total_a_count].start + 1;
            total_a_count ++ ;
        }
    }
}

void stat(int num) {
    printf("Partitions [Allocated memory = %d]:\n", alloc);
            for (int i = 0 ; i < a_count; i++){
                if (strcmp(p[i].command, "Free") != 0){
                    printf("Address [%d:%d] Process %s\n", p[i].start, p[i].end, p[i].command);  
                }
                       
            }      
}

void release_mem (Allocation *aloc,int *table_memory,int num){
    bool flag = false;
    int a = 0;
    int b = 0;

    while (a < num && !flag){
        if (table_memory[a] == aloc->p_number){
            printf("releasing memory for process %c%d", aloc->p_letter,aloc->p_number);
            b=a;
            while (table_memory[b] == aloc->p_number){
                table_memory[b] = -1;
                b++;
            }
            printf("Successfully released memory for process %c%d",aloc->p_letter,aloc->p_number);
            flag = true;
        }
        a++;
    }
    int i = 0 ;
    while (i<a_count)
    {
       if (! strncmp(p[i].command,aloc->command, 2)){
        strcpy(p[i].command, "Free");
       }
    }
    alloc -= b ;
}

void bestfit(Allocation *aloc, int *table_memory, int num) {
    int temp; 
    bool found = false;
    int mem_size = aloc->mem;
    int counter = 0;

    for (temp = 0; temp < num; temp++) {

        for ( counter; counter < mem_size; counter++) {
            if (table_memory[temp] == -1) {
                counter++;
            }
            else {
                counter = 0;
                aloc->f_index = temp + 1;
            }
            if (counter == aloc->mem) {
                aloc->l_index = temp;
                found = true;
                break; 
            }
            
        }
        
    }
    aloc->l_index++;

    if (found != true) {
        printf("Couldn't find a hole big enough to the required size.\n");

    }
    else {
        printf("Successfully allocated %d to process %c%d \n", aloc->mem, aloc->p_letter, aloc->p_number);
        int i = aloc->f_index;
        while (i < aloc->l_index) {
            table_memory[i] = aloc->p_number;
            i++;
        }
       p[a_count].start = aloc->f_index;
       p[a_count].end = aloc->l_index;
       strcpy(p[a_count].command, aloc->command);
       a_count++;

       alloc += aloc->l_index - aloc->f_index; 
    }
    


}

void firstfit(Allocation *aloc, int *table_memory, int num) {
    int temp = 0;
    int counter = 0;
    bool flag = false;
    for (int i = 0; i < num; i ++) {
        
        for (int j = 0; j < aloc->mem; j++) {
            temp ++;
            if (counter >= p->size) {
                p[a_count].start = aloc->f_index;
                p[a_count].end = aloc->l_index;
                strcpy(p[a_count].command, aloc->command);
                a_count++;

                alloc += aloc->l_index - aloc->f_index;
                temp = 0;
                flag = true;
                break;
            }
            
        }
        if (!flag) {
            printf("couldn't find a big enough hole to the required size of process. \n");
        }
    }
}
void worstfit(Allocation *aloc, int *table_memory, int num) {
    int temp = 0;
    int worstID = -1; 
    int counter = 0;
    bool flag = false;
    for (int i = 0; i < num; i ++) {
        
        for (int j = 0; j < aloc->mem; j++) {
            temp ++;
            if (counter >= p->size) {
                if (worstID == -1) {

                }
                
            }
            
        }
        if (!flag) {
            printf("couldn't find a big enough hole to the required size of process. \n");
        }
    }
}

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



void main(int argc, char *argv[]) {
   
    char input = argv[1];
    Allocation aloc;
    char *ptr;
    int num = strtol(input,&ptr,10);
    printf("Allocated %d bytes of memory.\n", num);

    //char ** temp = inputstr("RQ P3 1200000 B");
    //printf("results : %s",temp) ;
    //printf("\n");
    int table_memory [num];
    int i = 0;
    while (i<num){
        table_memory[i] = -1 ;
        i++;
    }

    char next_input[] = {}; 
        
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
    if (! strncmp(aloc.command, rq, strlen(rq)) ){
        if (! strncmp(aloc.algo, first, strlen(first))){
            //firstfit();
        }
        else if (! strncmp(aloc.algo, best, strlen(best)))
        {
            /* bestfit(); */
        }
        else if (! strncmp(aloc.algo, worst, strlen(worst)))
        {
            /* worstfit(); */
        }
        
        
    }
    else if (! strncmp(aloc.command, rl, strlen(rl)))
    {
        //release_mem ();
    }
    else if (! strncmp(aloc.command, status, strlen(status)))
    {
        /* stat (); */
    }
    
    

    }while (1);

    

}