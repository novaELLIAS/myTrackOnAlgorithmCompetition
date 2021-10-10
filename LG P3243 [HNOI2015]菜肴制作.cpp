#pragma G++ optimize (3)
#pragma GCC optimize ("Ofast", 3)

#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc(); register bool m = 0;
	while (c!='-'&&(c<'0'||c>'9') && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}

static void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}

#define Re register
#define maxn 100001

priority_queue <int> nico;
int deg[maxn], ecnt, sta[maxn], top;
int head[maxn], nex[maxn], to[maxn];

int main ()
{
	register int T = read ();
	register int x, y, n, m, fr;
	register bool flag;
	LOOP:while (T --)
	{
		n = read (), m = read (), ecnt = 0, top = 0, flag = false;
		memset (deg, 0, sizeof deg);
		memset (head, 0, sizeof head);
		for (Re int i = 0; i ^ m; ++ i)
		{
			x = read (), y = read ();
			if (x == y) {puts ("Impossible!"); goto LOOP;}
			nex[++ ecnt] = head[y], head[y] = ecnt, to[ecnt] = x, ++ deg[x];
		}
		for (Re int i = 1; i <= n; ++ i) if (!deg[i]) nico.push(i);
		while (!nico.empty())
		{
			fr = nico.top(), nico.pop(), sta[++ top] = fr;
			for (Re int i = head[fr]; i; i = nex[i])
			{
				if (!(-- deg[to[i]])) nico.push(to[i]);
			}
		}
		if (top ^ n) puts ("Impossible!");
		else {
			for (Re int i = n; i; -- i) write (sta[i]), putchar (' ');
			putchar ('\n');
		}
	}
	return 0;
}
