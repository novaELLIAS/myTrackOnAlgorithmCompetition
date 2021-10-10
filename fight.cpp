#pragma G++ optimize (3)

#include <cstdio>
#include <algorithm>

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
    return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline long long read ()
{
    register long long x = 0; register char c = gc();
    while (c < '0' || c > '9') c = gc();
    while (c>='0'&&c<='9') x = (x<<3) + (x<<1) + (c^'0'), c = gc();
    return x;
}
inline const long long& max (const long long& a, const long long& b) {return a>b? a:b;}
inline const long long& min (const long long& a, const long long& b) {return a<b? a:b;}

#define Re register
#define maxn 100001
typedef long long ll;

struct node {
	int id;
	long long x, t, eli, ege;
} dat[maxn];
long long dp[maxn];

inline bool cmp (Re node a, Re node b)
{
	return a.eli==b.eli? (a.ege<b.ege):(a.eli<b.eli);
}

inline ll  lof_find (register ll x, Re ll l, Re ll r)
{
	register ll mid, ans;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (dp[mid] >= x) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	return ans;
}
inline ll query (register ll n)
{
	register ll ret = 1, pos;
	for (Re ll i = 2; i <= n; ++ i)
	{
		if (dat[i].ege >= dp[ret]) ++ ret, dp[ret] = dat[i].ege;
		else pos = lof_find (dat[i].ege, 1, ret), dp[pos] = dat[i].ege;
	}
	return ret;
}
inline ll query2 (register ll psi, register ll n)
{
	register ll ret = 1, pos;
	for (Re ll i = psi + 1; i <= n; ++ i)
	{
		if (dat[i].ege >= dp[ret]) ++ ret, dp[ret] = dat[i].ege;
		else pos = lof_find (dat[i].ege, 1, ret), dp[pos] = dat[i].ege;
	}
	return ret;
}

signed main ()
{
	freopen ("fight.in", "r", stdin);
	freopen ("fight.out","w",stdout);
	
	register long long n = read ();
	for (Re ll i = 1; i <= n; ++ i)
		dat[i].id = i, dat[i].x = read (), dat[i].t = read ();
	register long long v = read ();
	for (Re ll i = 1; i <= n; ++ i)
		dat[i].eli = v * dat[i].t - dat[i].x, dat[i].ege = v * dat[i].t + dat[i].x;
	std::sort (dat + 1, dat + n + 1, cmp);
	dp[1] = dat[1].ege;
	register long long ans2 = query (n), sta = 0;
	for (Re ll i = 1; i <= n; ++ i)
		if (dat[i].ege < 0) dat[i].eli = -1;
	dat[0] = (node) {0, 0, 0};
	std::sort (dat, dat + n + 1, cmp);
	for (Re ll i = 0; i <= n; ++ i)
		if (!dat[i].id) {sta = i; break;}
	dp[1] = dat[sta].ege;
	
	printf ("%I64d %I64d", query2 (sta, n) - 1, ans2);
	
	fclose (stdin), fclose (stdout);
	return 0;
}
