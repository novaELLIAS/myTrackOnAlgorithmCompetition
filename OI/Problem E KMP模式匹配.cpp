#prag\
ma GCC optimize("Ofast")

#include <stdio.h>
#include <string.h>

#define maxn 300011
#define maxm 20001

char s1[maxn], s2[maxm];
int next[maxm];
int n, m, pt, cnt;

int main ()
{
	scanf ("%s%s", s1, s2);
	n = strlen (s1);
	m = strlen (s2);
	
	next[1] = next[0] = 0;
	pt = 0;
	for (int i = 1; i < m; i++)
	{
		while (pt && s2[i] != s2[pt])
		{
			pt = next[pt];
		}
		next[i+1] = s2[i]==s2[pt]? ++pt:0;
	}
	
	pt = 0;
	for (int i = 0; i < n; i ++)
	{
		while (pt && s1[i] != s2[pt]) pt = next[pt];
		pt += (s1[i] == s2[pt]? 1:0);
		if (pt == m)
		{
			printf ("%d", i + 2 - m);
			return 0;
		}
	}
	
	puts ("0");
	
	return 0;
}
