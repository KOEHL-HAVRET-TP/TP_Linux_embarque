#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//char pattern = 0x02;

int main(int argc, char * argv[]){
    char pattern = atoi(argv[1]);
    printf("Pattern 0x%2x", pattern);
    FILE* output_file;
    output_file = fopen("/dev/ensea-led","w+");
    if (output_file == NULL){
        fprintf(stderr, "Cannot open file for writing\n" );
        exit(-1);
    }
    if(1 != fwrite(&pattern,1,1,output_file)){
        perror("fwrite");
        return(1);
    }
    //fflush(output_file);
    //printf("Pattern %2x", pattern);
    fclose(output_file);
    return(0);
}
