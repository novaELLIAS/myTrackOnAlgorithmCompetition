#prag\
ma GCC optimize("Ofast")

#include <stdio.h>
#include <string.h>

#define maxr 10001
#define maxc 76

int r, c, ans1, ans2;
char mapp[maxr][maxr], ss[maxc][maxr];
int next[maxr];

inline int getnext (int len,char s[][maxr])
{
	memset (next, 0, sizeof next);
	int pt = 0;
	for (int i = 1; i < len; i ++)
	{
		pt = next[i];
		while (pt && strcmp (s[i], s[pt])) pt = next[pt];
		next[i+1] = !strcmp (s[i], s[pt])? ++pt:0;
	}
	return len - next[len];
}

int main ()
{
	scanf ("%d %d", &r, &c);
	
	for (int i = 0; i < r; i ++)
	{
		getchar ();
		for (int j = 0; j < c; j ++)
		{
			mapp[i][j] = getchar();
			ss[j][i] = mapp[i][j];
		}
	}
	
	ans1 = getnext (r, mapp);
	ans2 = getnext (c, ss);
	
	printf ("%d", ans1*ans2);
	
	return 0;
}
