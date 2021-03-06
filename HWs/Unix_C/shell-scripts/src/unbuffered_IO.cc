#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

#define BUFFSIZE 4096

int err_sys(const char *frmt, ...)
{
	perror(frmt);
	exit(1);
}

int
main(void)
{
	int n;
	char buf[BUFFSIZE];

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
	{
		if(write(STDOUT_FILENO, buf, n) != n)
			err_sys("write error");
	}

	if(n<0)
		err_sys("read error.");

	exit(0);
}