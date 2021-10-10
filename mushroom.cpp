#pragma G++ optimize ("Ofast", 3)

#include <cstdio>
#include <algorithm>

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc(); register bool m = 0;
	while ((c<'0'||c>'9') && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
static void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (int x) {write (x); putchar ('\n');}

#define Re register
#define maxn 200011

#define Re register

inline const int& maxx (const int& aa, const int& bb) {return aa>bb? aa:bb;}
inline const int& minn (const int& aa, const int& bb) {return aa<bb? aa:bb;}
inline long long abss (int x) {return x<0? -x:x;}

int n, m, kia[maxn], aim[maxn];

inline bool nico_check (int lim)
{
	register int i,j = 0, k;
	for (i = 0; j < m && i < n; ++ i)
	{
		if (kia[i] - lim > aim[j]) return false;
		if (kia[i] > aim[j])
		{
			k = maxx ((lim - kia[i] + aim[j]) >> 1, lim - ((kia[i] - aim[j])<<1));
			k = maxx (k, 0ll) + kia[i];
		} else k= lim + kia[i];
		while(j < m && aim[j] <= k) ++ j;		
	}
	return j > (m-1);	
}

int main ()
{
	freopen ("mushroom.in", "r", stdin);
	freopen ("mushroom.out","w",stdout);
	
	n = (int) read (), m = (int) read ();
	for (Re int i = 0; i ^ n; ++ i) kia[i] = read ();
	for (Re int i = 0; i ^ m; ++ i) aim[i] = read ();
	std::sort (kia, kia + n); std::sort (aim, aim + m);
	
	register long long l = 0, r = aim[m-1] << 1, mid, ans;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (nico_check (mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	
	printf ("%d", ans);
	
	SJB: return 0;
}
