// Load large text file in memory.

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define STEP_SIZE 100;
char ** load_file(char* file_name);


int main(int argc, char* argv[]){

    if(argc==1){
        fprintf(stderr, "File name not supplied: \n");
        exit(1);
    }

    char* file_name = argv[1];

    char** words = load_file(file_name);
    if(!words){
        fprintf(stderr, "Can't build data structure");
        exit(1);
    }

    for(int i = 0; i < 5; i++){
        printf("%s\n", words[i]);
    }
    printf("Done\n");

    return 0;
}


char ** load_file(char* file_name){
    printf("%s\n", file_name);
    FILE *fptr = fopen(file_name, "r");
    if(fptr==NULL){
        fprintf(stderr, "Can not open file\n");
        exit(1);
    }

    char buff[1000]; // reading 1000 chars at once in buffer
    char** lines = NULL; // char* lines[] - array of char pointers
    int i = 0;
    int max_elts = 0;

    while(fgets(buff, 1000, fptr)){
        if(i==max_elts){
            max_elts += STEP_SIZE;
            char **new_arr = (char**)realloc(lines, max_elts*(sizeof(char *)));
            if(!new_arr){
                fprintf(stderr, "Can not realloc\n");
                exit(1);
            }
            lines = new_arr;
        }

        // trimming new line char, hello\n\0 -> hello\0
        buff[strlen(buff)-1] = '\0';
        int slen = strlen(buff);
        char *str = (char *)malloc((slen+1)*(sizeof(char)));
        strcpy(str, buff);
        lines[i] = str;
        i++;
    }

    // There might be a worst case when i == max_elts, in that case realloc
    if(i==max_elts){
        char **new_arr = (char**)realloc(lines, (i+1)*(sizeof(char *)));
        if(!new_arr){
            fprintf(stderr, "Can not realloc");
            exit(1);
        }
        lines = new_arr;
    }
    lines[i] = '\0';
    return lines;
}


// There are three cases with re-alloc
//      1. Array extends at same place, i.e. enough memory ahead
//      2. Array can not extend at same location and hence given new location.
//      3. Re-allocation can not be done.
// Re-alloc behaves like malloc when the first arguemnt is NULL
//
//
// char **lines  or char *lines[] -> array of char pointers
// int abc[] or int *abc -> both are equivalent. Arrays are passed by reference and arr name gives base address.
// Its important to type case the pointer to right type.
//
//
//
// Steps of c compilation
//      1. Pre-processing -> gcc -E <file_name.c> -> create processed code. A *.i file will be created after preprocessing.
//      2. Compiling -> gcc -S <file_name.c> -> will generate assembly language, or an intermediate compiled output. *.s file will be created
//      3. Assembly -> gcc -c <file_name.c> -> Now, the assembly code will be converted into binary or machine code. The *.s file will be taken as input, then, a file called *.o will be created. It will contain machine level instructions.
//      4. Linking -> gcc <file_name.c> Here, all of our machine code will be merged into a single one. An executable *.out file will be created, which will allow us to run the program.
