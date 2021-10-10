#prag\
ma GCC optimize("Ofast")

#include "stdio.h"
#include "string.h"

inline int fastread ();
inline void fastwrite (int);

#define maxn 5000110

int n;
char s[maxn];

int main ()
{
	n = fastread ();
	for (int x = 0; x < n; x += 72) scanf ("%s", s+x);
	/*
	n = fastread ();
	// for Linux
		getchar ();
	// end.
	for (int i = 0; i < n; i ++) s[i] = getchar ();
	*/
	
	int i = 0, j = 1, pt = 0;
	while (i < n && j < n)
	{
		pt = 0;
		while (s[(i+pt)%n] == s[(j+pt)%n] && pt < n) pt ++;
		if (pt == n)
		{
			fastwrite (i<j? i:j);
			return 0;
		}
		if (s[(i+pt)%n] > s[(j+pt)%n]) i = i+pt+1;
		else j = j+pt+1;
		if (i == j) j ++;
	}
	
	fastwrite (i<j? i:j);
	
	return 0;
}

inline int fastread ()
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
inline void fastwrite (int x)
{
	if(x < 0) x = -x, putchar('-');
	if(x > 9) fastwrite(x / 10);
	putchar(x%10 + '0');
}
