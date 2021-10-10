#pragma GCC optimize ("Ofast")

#include "stdio.h"
#define rint register int

short nico[40][40], n, x, y, _;

inline short read () {
	short sign = 1, n = 0;
	char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') sign = -1; c = getchar();}
	while(c >= '0' && c <= '9') n = ((n<<1)+(n<<3)) + c-'0',c = getchar();
	return sign*n;
}

int main ()
{
	n = read ();
	_ = n*n;
	x = 1, y = n/2+1;
	nico[x][y] = 1;
	
	for (rint i = 2; i <= _; i ++)
	{
		if (x == 1)
		{
			if (y != n)
			{
				x = n, y ++;
			} else {
				x ++;
			}
		} else {
			if (y == n)
			{
				y = 1, x --;
			} else {
				if (!nico[x-1][y+1]) x --, y ++;
				else x ++;
			}
		}
		nico[x][y] = i;
	}
	
	for (rint i = 1; i <= n; i ++)
	{
		for (rint j = 1; j <= n; j ++) printf ("%d ", nico[i][j]);
		putchar ('\n');
	}
	
	return 0;
}
