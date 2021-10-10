#pragma G++ optimize ("Ofast", 3)

#include <cstdio>
#include <string.h>
#include <map>

using namespace std;

static char buf[1<<14],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc(); register bool m = 0;
	while ((c < '0' || c > '9') && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}

typedef long long ll;
#define Re register
#define maxn 31
#define maxm 1001

inline const ll& max (const ll& a, const ll& b) {return a>b? a:b;}

const long long modn = 1234567891ll;
const long long base = 101;
int cnt, men[maxn], cck[maxn];
int dmax = -1;
map <long long, long long> sjb[maxn];
long long a[maxn], fac[maxn];
bool vis[maxn];

static long long nico_dfs (int ste, int las, int n)
{
	if (ste > n) return 1ll;
	register ll now = men[0], res = 0;
	memset (cck, 0, sizeof cck);
	for (Re int i = 0; i <= cnt; ++ i) if (i ^ las) ++ cck[men[i]];
	for (Re int i = 1; i <= dmax; ++ i) now = now * base + cck[i];
	now = now * base + (las? men[las]:0);
	if (sjb[ste][now]) return sjb[ste][now];
	if (men[0]) {-- men[0]; res = (res + nico_dfs (ste + 1, 0, n)) % modn; ++ men[0];}
	for (Re int i = 1; i <= cnt; ++ i)
	{
		if ((i^las) && men[i]) {-- men[i]; res = (res + nico_dfs (ste + 1, i, n)) % modn; ++ men[i];}
	}
	sjb[ste][now] = res;
	//printf ("%I64d\n", res);
	return res;
}

inline void nico_init (register int n)
{
	register int psi;
	for (Re int i = 1; i <= n; ++ i)
	{
		if (!vis[i])
		{
			vis[i] = true;
			psi = 0;
			for (Re int j = i + 1; j <= n; ++ j)
			{
				if (a[i] == a[j]) vis[j] = true, ++ psi;
			}
			if (psi==1) ++ men[0];
			else men[++ cnt] = psi;
			dmax = dmax<psi? psi:dmax;
		}
	}
}

int main ()
{
	register int n = read ();
	fac[0] = 1;
	for (Re int i = 1; i <= n; ++ i) a[i] = read(), fac[i] = i*fac[i-1] % modn;
	register int m = read ();
	for (Re int i = 1; i <= n; ++ i) a[i] = ((a[i]%modn)+modn)%modn;
	nico_init (n);
	register long long ans = 1ll;
	for (Re int i = 0; i <= cnt; ++ i) ans = ans * fac[men[i]] % modn;
	printf ("%I64d", ans*nico_dfs (1, 0, n) % modn);
	return 0;
}
