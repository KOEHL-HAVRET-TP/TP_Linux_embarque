#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    char buffer;
    FILE* output_file;
    output_file = fopen("/dev/ensea-led","r+");
    if (output_file == NULL){
        fprintf(stderr, "Cannot open file for reading\n" );
        exit(-1);
    }
    fread(&buffer,1,1,output_file);
    printf("0x%2x\n",buffer);
    //fclose(output_file);
    return(0);
}
