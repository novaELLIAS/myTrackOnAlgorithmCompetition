#pragma G++ optimize (3)
#pragma GCC optimize ("Ofast", 3)

#include <cstdio>

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;	
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc(); register bool m = 0;
	while (c < '0'|| c > '9') {if (c == '-') m = true; c = gc();}
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}

#define Re register
#define maxn 1051
#define sqr(x) ((x)*(x))

struct node {
	int x, y, r;
} dat[maxn];

int que[maxn], fa[maxn];
double spe[maxn];
bool vis[maxn];

int main ()
{
	register int n = read (), aimx = read (), aimy = read ();
	register int sta, aim;
	for (Re int i = 1; i <= n; ++ i)
	{
		dat[i].x = read (), dat[i].y = read (), dat[i].r = read ();
		if (!dat[i].x && !dat[i].y) sta = i;
		if (dat[i].x == aimx && dat[i].y == aimy) aim = i;
	}
	
	register int head = 0, tail = 1, fr;
	register double nsp;
	que[tail] = sta, vis[sta] = true, spe[sta] = 10000.0;
	while (head < tail)
	{
		head ++;
		fr = que[head];
		for (Re int i = 1; i <= n; ++ i)
		{
			if (!vis[i] && sqr(dat[fr].x-dat[i].x)+sqr(dat[fr].y-dat[i].y)==sqr(dat[fr].r+dat[i].r))
			{
				vis[i] = true, spe[i] = spe[fr] * 1.0 * dat[fr].r / dat[i].r, fa[i] = fr;
				if (i == aim) {head = tail + 1; break;}
				que[++ tail] = i;
			}
		}
	}
	
	register double ans = 0.0;
	for (Re int i = aim; i; i = fa[i]) ans += spe[i];
	
	printf ("%d", (int) ans);
	
	return 0;
}
