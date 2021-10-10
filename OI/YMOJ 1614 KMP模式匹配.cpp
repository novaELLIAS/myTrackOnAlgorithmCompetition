#include <stdio.h>
#include <string.h>

inline int fastread();
inline void fastwrite(int);
inline void fastwriteline(int);

#define maxn 300012
#define maxm 20005

char ori[maxn], cmp[maxm];
int kmp[maxm];
int lenori, lencmp;

int main()
{
	scanf("%s%s", ori, cmp);
	lenori = strlen(ori);
	lencmp = strlen(cmp);
	
	int pt = 0;
	for (int i = 1; i <lencmp; i ++)
	{
		while (pt > 0 && cmp[i] != cmp[pt])
		{
			pt = kmp[pt];
		}
		kmp[i+1] = cmp[i]==cmp[pt]? ++pt:0;
	}
	
	pt = 0;
	for (int i = 0; i < lenori; i ++)
	{
		while (pt > 0 && ori[i] != cmp[pt])
		{
			pt = kmp[pt];
		}
		if (ori[i] == cmp[pt]) pt ++;
		if (pt == lencmp)
		{
			printf("%d", i + 2 - lencmp);
			//putchar('\n');
			return 0;
		}
	}
	//for (int i = 1; i <= lencmp; i ++) fastwrite(kmp[i]);
	putchar('0');
	return 0;
}

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
inline void fastwrite(int x)
{
	if(x < 0) x = -x, putchar('-');
	if(x > 9) fastwrite(x / 10);
	putchar(x%10 + '0');
}
inline void fastwriteline(int x)
{
	fastwrite(x);
	putchar('\n');
}
