#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <unistd.h>

int main(void)
{
	int id;
	char *address;

	id = shmget(IPC_PRIVATE, sizeof(char)*11, IPC_CREAT|0666); //10文字分用意

	address = shmat(id,NULL,0);

	while(1)
	{
		printf("共有メモリ(id=%d)のデータは%s\n",id,address);

		if(strcmp(address,"quit")==0)
			break;

		sleep(1);
	}

	shmctl(id,IPC_RMID,0);


	return 0;
}
