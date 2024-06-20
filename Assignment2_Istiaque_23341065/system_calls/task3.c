#include <stdio.h>
#include <unistd.h>

signed main()
{
	int a, b, c, count = 1;
	a = fork();
	b = fork();
	c = fork();
	if (a == 0)
	{
    	if (getpid() & 1)
    	{
        	fork();
        	count++;
    	}
	}
	else if (b == 0)
	{
    	if (getpid() & 1)
    	{
        	fork();
        	count++;
    	}
	}
	else if (c == 0)
	{
    	if (getpid() & 1)
    	{
        	fork();
        	count++;
    	}
	}
	else
	{
    	count+=3;
    	printf("%d\n", count);
	}
}