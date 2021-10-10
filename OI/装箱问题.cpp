#include <stdio.h>

#define max(x,y) x>y? x:y
#define min(x,y) x<y? x:y

inline int fastread()
{
	int sign = 1, n = 0;
	char c = getchar();
	while(c < '0' || c > '9')
	{
		if(c == '-') sign = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')
	{
		n = n*10 + c-'0';
		c = getchar();
	}
	return sign*n;
}

#define maxn 31
#define maxv 20001

int v, n, nico[maxv], wei[maxn];

int main()
{
	v = fastread();
	n = fastread();
	for(int i = 1; i <= n; i ++) wei[i] = fastread();
	for(int i = 1; i <= n; i ++)
	{
		for(int j = v; j >= wei[i]; j --)
		{
			nico[j] = max(nico[j], nico[j-wei[i]]+wei[i]);
		}
	}
	printf("%d", v-nico[v]);
}
