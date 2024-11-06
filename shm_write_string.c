#include <stdio.h>
#include <string.h>
#include <sys/shm.h>


#include <stdlib.h>


int main(int argc, char *argv[])
{
	int id;
	char *address;

	if(argc>=3)
	{
		id = atoi(argv[1]);

		address = (char *)shmat(id,NULL,0);
		strncpy(address, argv[2],10);	//10文字分だけコピー
		address[10]='\0';				//\0文字付加
	}

	return 0;
}
	


