#include "stdio.h"

double b[5001];
int c[5001];
bool a[200000001];
int n;

inline int read()
{
	register int x=0,t=1;
	register char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')
	{
		t=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*t;
}

int main ()
{
	freopen ("light.in", "r", stdin);
	freopen ("light.out", "w", stdout);
	 
	n = read ();
	for (register int i = 1; i <= n; i ++)
	{
		scanf ("%lf", &b[i]);
		c[i] = read ();
		for (register int j = 1; j <= c[i]; j ++)
		{
			a[(int)(j*b[i])] = !a[(int)(j*b[i])];
		}
	}
	
	for (register int i = 1; ; i ++)
	{
		if (a[i])
		{
			printf ("%d", i);
			return 0;
		}
	}
	
	return 0;
}
