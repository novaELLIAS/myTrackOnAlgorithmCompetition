#include "stdio.h"
#include "queue"

using namespace std;

int n, m, k;
long long cnt;

struct node {
	int x, y;
	int val;
	bool can;
	friend bool operator < (node aa, node bb)
	{
		if ((aa.can && bb.can) || (!aa.can && !bb.can)) return aa.val < bb.val;
		else {
			if (aa.can) return false;
			if (bb.can) return true;
		}
	}
} a[201][201];

priority_queue <node> q;

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

inline void input ()
{
	n = read ();
	m = read ();
	k = read ();
	register char c;
	for (register int i = 1; i <= n; i ++)
	{
		for (register int j = 1; j <= m; j ++)
		{
			a[i][j].x = i;
			a[i][j].y = j;
			a[i][j].val = read ();
			scanf ("%c", &c);
			if (c == 'Y') a[i][j].can = 1;
			else a[i][j].can = 0;
		}
	}
}

inline void fastwrite (long long x)
{
	if(x < 0) x = -x, putchar('-');
	if(x > 9) fastwrite(x / 10);
	putchar(x%10 + '0');
}

int main ()
{
	input ();
	
	for (register int i = 1; i <= n; i ++)
	{
		for (register int j = 1; j <= m; j ++)
		{
			printf ("%d %d  ", a[i][j].val, a[i][j].can);
		}
		putchar ('\n');
	}
	
	for (register int i = 1; i <= m; i ++) q.push (a[n][i]);
	
	node fro;
	
	while (!q.empty () && k)
	{
		fro = q.top ();
		q.pop ();
		if (!fro.can) k --;
		cnt += (long long)fro.val;
		if (fro.x > 1) q.push (a[fro.x-1][fro.y]);
	}
	
	fastwrite (cnt);
	
	return 0;
}
