#pragma G++ optimzie ("Ofast", 3)

#include <cstdio>

using namespace std;

const int ELAS = 1<<14;
static char buf[ELAS], *p1 = buf, *p2 = buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc();
	while (c < '0' || c > '9') c = gc();
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return x;
}
static void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (int x) {write (x); putchar ('\n');}

#define Re register
#define maxn 100001

int dat[maxn], ans[maxn];
bool vis[maxn];

int main ()
{
	freopen ("suffixes.in", "r", stdin);
	freopen ("suffixes.out","w",stdout);
	
	register int n = read (), m = read (), cnt = 0;
	for (Re int i = 1; i <= n; ++ i) dat[i] = read ();
	for (Re int i = n; i; -- i)
	{
		if (!vis[dat[i]]) vis[dat[i]] = true, ans[i] = ++ cnt;
		else ans[i] = cnt;
	}
	
	while (m --) writelen (ans[read ()]);
	
	return 0;
}
