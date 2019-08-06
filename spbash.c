#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define COM_SIZE 10

int main()
{
	char path[] ="/bin/ls";
	pid_t curpid;
	char buf[40];
	fgets(buf, 38, stdin);
	strtok(buf, "\n");
	char *pch[COM_SIZE];
	int i = 0;
	pch[i] = strtok(buf, " ");
	do
	{
//		printf("\n i =%d, str = '%s'", i, pch[i]);
		i++;
		pch[i] = strtok(NULL, " ");
	}while ((pch[i] != NULL) && (i<COM_SIZE));
	i--;

	curpid = fork();
	if (curpid == 0)
	{
		execl(path, pch[0],pch[1], NULL);
	}else{
		wait(0);
	}

//	execl("/bin/ls", "ls", "-la", NULL);
	return 0;
}
