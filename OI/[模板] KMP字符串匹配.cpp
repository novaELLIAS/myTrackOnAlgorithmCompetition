#prag\
ma GCC optimize("Ofast")

#include <stdio.h>
#include <string.h>

#define maxn 20001
#define maxm 10001

char s1[maxn], s2[maxm];
int next[maxm];
int n, m, pt, cnt;

int main ()
{
	scanf ("%d%d%s%s", &n, &m, s1, s2);

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
		if (pt == m) cnt ++;
	}

	if (cnt == 0) puts ("Substring Not Found");
	else printf ("%d", cnt);

	return 0;
}
