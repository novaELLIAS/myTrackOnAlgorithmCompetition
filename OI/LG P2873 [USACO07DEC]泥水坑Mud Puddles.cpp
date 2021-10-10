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
	while (c!='-'&&(c<'0'||c>'9') && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
template <typename T>
static void write (T x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}

#define Re register
#define maxn 501
#define maxs 1001
#define maxp 10001

struct QueNode {
	int x, y, ste;
} que[10000001];

bool pol[maxs][maxs];
bool vis[maxs][maxs];
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};

int main ()
{
	register int tx = read () + 500, ty = read () + 500, n = read ();
	register int x, y;
	for (Re int i = 0; i ^ n; ++ i)
	{
		x = read () + 500, y = read () + 500;
		pol[x][y] = true;
	}
	
	register int nx, ny;
	register int head = 0, tail = 1, ste;
	que[tail] = (QueNode){500, 500, 0};
	while (head < tail)
	{
		nx = que[++ head].x, ny = que[head].y, ste = que[head].ste;
		if (vis[nx][ny] || pol[nx][ny]) continue;
		if (nx == tx && ny == ty) return printf ("%d", ste), 0;
		vis[nx][ny] = true;
		for (Re int i = 0; i ^ 4; ++ i)
		{
			x = nx + dx[i], y = ny + dy[i];
			if (!vis[x][y] && !pol[x][y] && x>=0 && y>=0 && x<=1000 && y<=1000)
			{
				que[++ tail] = (QueNode){x, y, ste + 1};
			}
		}
	}
	puts ("No Solution");
	return 0;
}
