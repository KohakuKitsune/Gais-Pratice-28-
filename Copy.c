#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

#define MaxLen 1024
int main(int argc, char**argv){
	int fd_in,fd_out;
	int input_size;
	char *buf = (char*)  malloc(sizeof(char)*(MaxLen+1));
	
	fd_in = open(*(argv+1),O_RDONLY);
	fd_out = open(*(argv+2),O_WRONLY|O_TRUNC|O_CREAT,00600);
	
	if(fd_in == -1){
		printf("Open input file error!!!\n");
		return 0;
	}
	if(fd_out == -1){
		printf("Open output file error!!!\n");
		return 0;
	}

	while(1){
		input_size = read(fd_in,buf,MaxLen);
		//printf("%d\n",input_size);
		//printf("%s",buf);	
		if(input_size <= 0) break;

		write(fd_out,buf,input_size);
	}
	free(buf);
	close(fd_in);
	close(fd_out);
	return 0;
}
