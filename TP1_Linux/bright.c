#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
FILE* output_file = fopen("/sys/class/leds/fpga_led1/brightness", "w+");
	if(!output_file1){
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	fwrite("1", 1, 1, output_file1);
	fclose(output_file1);
	exit(EXIT_SUCCESS);
}*/




int main(void){
	FILE* output_file[9];
	output_file[0] = fopen("/sys/class/leds/fpga_led1/brightness", "w+");
	output_file[1] = fopen("/sys/class/leds/fpga_led2/brightness", "w+");
	output_file[2] = fopen("/sys/class/leds/fpga_led3/brightness", "w+");
	output_file[3] = fopen("/sys/class/leds/fpga_led4/brightness", "w+");
	output_file[4] = fopen("/sys/class/leds/fpga_led5/brightness", "w+");
	output_file[5] = fopen("/sys/class/leds/fpga_led6/brightness", "w+");
	output_file[6] = fopen("/sys/class/leds/fpga_led7/brightness", "w+");
	output_file[7] = fopen("/sys/class/leds/fpga_led8/brightness", "w+");
	output_file[8] = fopen("/sys/class/leds/fpga_led9/brightness", "w+");
	while(1){
	for(int i=0;i<9;i++){
		if(!output_file[i]){
			perror("fopen");
			exit(EXIT_FAILURE);
		}
		fwrite("1", 1, 1, output_file[i]);
		fflush(output_file[i]);
		usleep(100000);
		fwrite("0", 1, 1, output_file[i]);
		fflush(output_file[i]);
	}
	}
	exit(EXIT_SUCCESS);
}

