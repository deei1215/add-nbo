#include <cstdio>
#include <string.h>
#include <stdint.h> // for uint8_h, uint32_h
#include <netinet/in.h> // for ntohs, htonl
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int i=argc;		
	
	uint32_t net1, net2, host1, host2;

	FILE *fd1 = fopen(argv[1], "rb");
	FILE *fd2 = fopen(argv[2], "rb");
	fread(&net1, sizeof(uint32_t), 1, fd1);
	fread(&net2, sizeof(uint32_t), 1, fd2);
	host1 = ntohl(net1);
	host2 = ntohl(net2);
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", host1, host1, host2, host2, host1+host2, host1+host2);
	fclose(fd1);
	fclose(fd2);
	return 0;
}
