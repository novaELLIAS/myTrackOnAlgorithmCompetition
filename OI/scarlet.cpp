#pragma G++ optimize ("Ofast", 3)

#include <cstdio>

using namespace std;

#define Re register
#define maxn 501
#define maxq 10000001

inline char gc()
{
	static char buf[1<<14],*p1=buf,*p2=buf;
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0;register char c = gc();
	while (c < '0' || c > '9') c = gc();
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return x;
}
static void write (register int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
inline void writelen (register int x) {write (x), putchar ('\n');}

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};

struct QueNode {
	int x, y;
} que[maxq];
int head, tail;

int n, m, tim[maxn][maxn], kill[maxn][maxn];

inline void niconiconiconiconiconiconiconiconiconiconiconiconiconiconiconiconiconiconiconiconiconiconi_bfs ()
{
	register int x, y;
	while (head < tail)
	{
		++ head;
		for (Re int i = 0; i ^ 4; i ++)
		{
			x = que[head].x + dx[i], y = que[head].y + dy[i];
			if (kill[x][y] || x < 1 || x > n || y < 1 || y > m) continue;
			kill[x][y] = true, que[++ tail] = (QueNode) {x, y}, tim[x][y] = tim[que[head].x][que[head].y] + 1;
		}
	}
}

int main ()
{
	freopen ("scarlet.in","r",stdin); freopen ("scarlet.out","w",stdout);
	n = read (), m = read (); register int A = read (), B = read (), x ,y;
	for (Re int i = 0; i ^ A; i ++) x = read (), y = read (), que[++ tail] = (QueNode) {x, y}, kill[x][y] = true;
	niconiconiconiconiconiconiconiconiconiconiconiconiconiconiconiconiconiconiconiconiconiconi_bfs ();
	for (Re int i = 0; i ^ B; i ++) x = read (), y = read (), writelen (tim[x][y]);
	return 0;
}
