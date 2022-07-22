#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

# define MAX 10

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
    char p_number[3];
    long n

};


typedef struct h
{
    int holes;
    int partitions;

} Holes;

typedef struct allocation 
{
    char command[100];
    char pid[100];
    int memNeeded;
    char format[20];
    int iPID;

    int firstIndex; 
    int lastIndex;
    int length;

} Allocation; 

int allocate_mem (){
   
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
    char input;
    input = atoi(argv[1]);
    Process *p = NULL;
    Holes *h = NULL;

    printf("Allocated %d bytes of memory.\n", input);

    //char ** temp = inputstr("RQ P3 1200000 B");
    //printf("results : %s",temp) ;
    //printf("\n");
    printf("command>");

<<<<<<< HEAD

=======
    //get user input
    do {
        
        printf("command>");
>>>>>>> 844df7faa0cad2dd23c6deb7b1638a332ce8d693

        //read until usr presses enter
        fgets(usrInput, 30, stdin);
        char *token;
        token = strtok(usrInput, " ");
        int j = 0;

        while (token != NULL){
            if (j == 0){
                strcpy(userArrgs.command, token);
                uppercase(userArrgs.command);
            }else if (j == 1){
                strcpy(userArrgs.pid, token);
                uppercase(userArrgs.pid);
                userArrgs.iPID = (int) userArrgs.pid[1];
            }else if (j == 2){
                userArrgs.memNeeded = (int) atoi(token);
            }else if(j == 3){
                strcpy(userArrgs.format, token); 
                uppercase(userArrgs.format);  
            }
            j++;
            token = strtok(NULL, " ");  
        }

}