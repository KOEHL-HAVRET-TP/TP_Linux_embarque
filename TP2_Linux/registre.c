#include <sys/mman.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>

int main(){
    uint32_t *p;
	int fd = open("/dev/mem", O_RDWR);
	p = (uint32_t*)mmap(NULL,4,PROT_WRITE|PROT_READ,MAP_SHARED,fd,0xFF203000);
	*p = (1<<8);
}
