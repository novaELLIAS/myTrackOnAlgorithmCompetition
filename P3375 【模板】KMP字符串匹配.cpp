#include <stdio.h>
#include <string.h>

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

#define maxn 1000010

char wod[maxn], cmp[maxn];
int kmp[maxn];
int lenwod, lencmp;

int main()
{
	scanf("%s%s", wod, cmp);
	kmp[0] = kmp[1] = 0;
	lenwod = strlen(wod);
	lencmp = strlen(cmp);
	/*
	puts("-----strlen-----");
	fastwriteline(lenwod);
	fastwriteline(lencmp);
	puts("-----------------");
	*/
	kmp[0] = kmp[1] = 0;
	int pt = 0;
	for(int i = 1; i < lencmp; i++)
	{
		while(pt>0 && cmp[i] != cmp[pt])
		{
			pt = kmp[pt];
		}
		kmp[i+1] = cmp[i]==cmp[pt]? ++pt:0;
	}
	/*
	puts("-----KMP-----");
	for (int i = 1; i <= lencmp; i ++) printf("%d ", kmp[i]);
	puts(""); puts("-------------");
	*/
	pt = 0;
	for(int i = 0; i < lenwod; i ++)
	{
		while(pt>0 && wod[i] != cmp[pt])
		{
			pt = kmp[pt];
		}
		if(wod[i] == cmp[pt]) pt ++;
		if(pt == lencmp)
		{
			fastwriteline(i + 2 - lencmp);
		}
	}
	for(int i = 1; i <= lencmp; i ++)
	{
		fastwrite(kmp[i]);
		putchar(' ');
	}
	return 0;
}
