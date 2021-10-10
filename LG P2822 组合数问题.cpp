#pragma GCC optimize ("Ofast", 3)

#include <cstdio>

typedef long long ll;
#define maxn 2011
#define Re register

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

long long ans[maxn][maxn], ccc[maxn][maxn];

inline void c_generator (register int k)
{
	register int i, j;
	ccc[0][0] = ccc[1][1] = ccc[1][0] = 1ll;
	for (i=2; i<=2000; ++i)
	{
		ccc[i][0] = 1ll;
		for (j=1; j<=i; ++j)
		{
			ccc[i][j] = (ccc[i-1][j-1] + ccc[i-1][j]) % k;
			ans[i][j] = ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1]+(ccc[i][j]==0);
		}
		ans[i][i+1] = ans[i][i];
	}
}

inline void c_checker ()
{
	register int i, j;
	for (i=0; i<=10; ++i) {
		for (j=0; j<=10; ++j)
			printf("%d ", ccc[i][j]);
		putchar ('\n');
	}
}

signed main ()
{
	register int _=read(), k=read();
	register int x, y;
	c_generator (k);
	//c_checker();
	while (_ --)
	{
		x=read(), y=read();
		y=y>x? x:y;
		printf("%lld\n", ans[x][y]);
	} return 0;
}
