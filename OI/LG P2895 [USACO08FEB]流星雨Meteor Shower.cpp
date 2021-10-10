#pragma G++ optimize (3)
#pragma GCC optimize ("Ofast", 3)

#include <cstdio>
#include <cstring>

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

inline const int& min (const int& a, const int& b) {return a<b? a:b;}

#define Re register
#define maxn 401

struct QueNode {
	int x, y, ste;
} que[160001];

int tim[maxn][maxn];
bool vis[maxn][maxn];
const int dx[5] = {0, 1, 0, -1, 0};
const int dy[5] = {-1, 0, 1, 0, 0};

int main ()
{
	register int m = read ();
	std::memset (tim, 0x3f3f3f3f, sizeof tim);
	register int x, y, t, nx, ny;
	for (Re int i = 0; i ^ m; ++ i)
	{
		x = read (), y = read (), t = read ();
		for (Re int j = 0; j ^ 5; ++ j)
		{
			nx = x + dx[j], ny = y + dy[j];
			if (nx>=0 && ny>=0 && nx<=400 && ny<=400)
				tim[nx][ny] = min (tim[nx][ny], t);
		}
	}
	
	if (tim[0][0] == 0x3f3f3f3f) return printf ("0"), 0;
	register int head = 0, tail = 1, ste;
	que[tail] = (QueNode){0, 0, 0}, vis[0][0] = true;
	while (head < tail)
	{
		nx = que[++ head].x, ny = que[head].y, ste = que[head].ste;
		for (Re int i = 0; i ^ 4; ++ i)
		{
			x = nx + dx[i], y = ny + dy[i];
			if (!vis[x][y] && ste+1 < tim[x][y] && x>=0 && y>=0 && x<=400 && y<=400)
			{
				if (tim[x][y] == 0x3f3f3f3f) return printf ("%d", ste + 1), 0;
				que[++ tail] = (QueNode){x, y, ste + 1}, vis[x][y] = true;
			}
		}
	}
	printf ("-1");
	return 0;
}
