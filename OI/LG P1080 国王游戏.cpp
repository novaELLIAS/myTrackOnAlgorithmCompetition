#pragma GCC optimize ("Ofast")

#include "stdio.h"
#include "string.h"
#include <algorithm>

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

struct node {
	int name;
	int a, b, val;
} data[1001];

inline bool cmp (node x, node y) { return x.val < y.val;}

int ans[10001], preans[10001], temp[10001];

inline void xxxx (int x)
{
	memset (temp, 0, sizeof temp);
	for (register int i = 1; i <= preans[0]; i ++)
	{
		preans[i] = preans[i] * x;
		temp[i+1] += preans[i] / 10;
		preans[i] %= 10;
	}
	
	for (register int i = 1; i <= preans[0] + 4; i ++)
	{
		preans[i] += temp[i];
		if (preans[i] >= 10)
		{
			preans[i+1] += preans[i] / 10;
			preans[i] %= 10;
		}
		if (preans[i] && preans[0] < i) preans[0] = i;
	}
}

inline void down (int x)
{
	memset (temp, 0, sizeof temp);
	int q = 0;
	for (register int i = preans[0]; i >= 1; i --)
	{
		q *= 10;
		q += preans[i];
		temp[i] = q / x;
		if (!temp[0] && temp[i]) temp[0] = i;
		q %= x;
	}
}

inline bool cmpp ()
{
	if (temp[0] == ans[0])
	{
		for (register int i = temp[0]; i >= 1; i --)
		{
			if (temp[i] > ans[i]) return true;
			if (temp[i] < ans[i]) return false;
		}
	}
	if (temp[0] > ans[0]) return true;
	if (temp[0] < ans[0]) return false;
}

inline void swapp ()
{
	memset (ans, 0, sizeof ans);
	for (register int i = temp[0]; i >= 0; i --) ans[i] = temp[i];
}

inline void work (int pos)
{
	xxxx (data[pos-1].a);
	down (data[pos].b);
	if (cmpp ()) swapp ();
}

inline void write ()
{
	for (register int i = ans[0]; i >= 1; i --) printf ("%d", ans[i]);
}

int main ()
{
	int n = fastread ();
	for (register int i = 0; i <= n; i ++)
	{
		data[i].a = fastread ();
		data[i].b = fastread ();
		data[i].val = data[i].a * data[i].b;
	}
	
	std::sort (data+1, data+n+1, cmp);
	
	preans[0] = preans[1] = 1;
	
	for (register int i = 1; i <= n; i ++) { work (i);}
	
	write ();
	
	return 0;
}
