#pragma G++ optimize (3)

#include <cstdio>

#define maxn 101
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

int xx[maxn], yy[maxn], zz[201], kk[201];
int cnt[maxn][maxn];

signed main ()
{
	register int n = read (), k = read ();
	register int x, y, ans = 0;
	for (Re int i = 1; i <= k; ++ i)
		x = read (), y = read (), ++ xx[x], ++ yy[y], ++ zz[x+y-1], ++ kk[x-y+n], ++ cnt[x][y];
	for (Re int i = n; i; -- i)
		for (Re int j = n; j; -- j)
		{
			if (cnt[i][j] && xx[i] + yy[j] + zz[i+j-1] + kk[i-j+n] - cnt[i][j] - (cnt[i][j]<<1) == k) ++ ans;
			else if (!cnt[i][j] && xx[i] + yy[j] + zz[i+j-1] + kk[i-j+n] == k) ++ ans;
		}
	printf ("%d", ans);
	return 0;
}
