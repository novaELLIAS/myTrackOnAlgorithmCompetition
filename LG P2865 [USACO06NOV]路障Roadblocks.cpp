#pragma G++ optimize (3)

#include <cstdio>
#include <cstring>
#include <queue>

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc();
	while (c < '0' || c > '9') c = gc();
	while (c>='0'&&c<='9') x = (x<<3) + (x<<1) + (c^'0'), c = gc();
	return x;
}

#define Re register
#define maxn 5001
#define maxe 200001

struct node {
	int id, val;
	bool operator < (const node & a) const {
		return val > a.val;
	}
};

std::priority_queue <node> que;
int head[maxn], wei[maxe], too[maxe], nxt[maxe],ecnt;
int disf[maxn], diss[maxn];

int main ()
{
	register int n = read (), m = read ();
	register bool flag;
	for (Re int i = 1; i <= n; ++ i) disf[i] = diss[i] = 0x3f3f3f3f;
	register int fr, to, va;
	while (m --)
	{
		fr = read (), to = read (), va = read ();
		nxt[++ ecnt] = head[fr], too[ecnt] = to, wei[ecnt] = va, head[fr] = ecnt;
		nxt[++ ecnt] = head[to], too[ecnt] = fr, wei[ecnt] = va, head[to] = ecnt;
	}
	disf[1] = 0, que.push ((node) {1, 0});
	while (!que.empty())
	{
		fr = que.top().id, que.pop();
		for (Re int i = head[fr]; i; i = nxt[i])
		{
			to = too[i], va = wei[i], flag = false;
			if (disf[fr] + va < disf[to]) disf[to] = disf[fr] + va, flag = true;
			if (disf[fr] + va > disf[to] && disf[fr] + va < diss[to])
				diss[to] = disf[fr] + va, flag = true;
			if (diss[fr] + va < diss[to]) diss[to] = diss[fr] + va, flag = true;
            if (flag) que.push((node) {to, disf[to]});
		}
	}
	printf ("%d", diss[n]);
	return 0;
}
