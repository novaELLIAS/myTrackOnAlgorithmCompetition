#pragma G++ optimize (3)

#include <cstdio>

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
inline const int& max (const int& a, const int& b) {return a>b? a:b;}

#define maxn 100001
#define hasm 100000
#define Re register

int hash[maxn], cnt[maxn], que[maxn + 100];

inline int get_hash (register int x)
{
	register int ret = x % hasm;
	while (hash[ret] && (hash[ret] != x)) ret = (ret+1) % hasm;
	return ret;
}

signed main ()
{
	freopen ("sugata.in", "r", stdin);
	freopen ("sugata.out","w",stdout);
	
	register int n = read (), k = read (), tot = 0, ans = 0;
	register int head = 0, tail = 0, sjb, nk = k + 1, fr;
	for (Re int i = 1; i <= n; ++ i)
	{
		fr = read (), sjb = get_hash(fr), que[++ tail] = fr;
		if (!hash[sjb])
		{
			hash[sjb] = fr, ++ tot;
			while (tot > nk)
			{
				fr = que[++ head], fr = get_hash (fr);
				if (!(-- cnt[fr])) hash[fr] = 0, -- tot;
			}
		}
		++ cnt[sjb], ans = max (ans, cnt[sjb]);
	}
	printf ("%d", ans);
	
	fclose (stdin), fclose (stdout);
	
	return 0;
}
