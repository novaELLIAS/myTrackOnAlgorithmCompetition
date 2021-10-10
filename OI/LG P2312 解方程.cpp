
#pragma GCC optimize ("Ofast")

#include <stdio.h>
#include <ctype.h>
#include <queue>

using namespace std;

#define rint register int
typedef long long ll;
#define maxn 101
const int mod1 = 1e3+9, mod2 = 1e9+7;

const int str = 1 << 20;
char buf[str], *s, *t;

inline char gc() { return s==t&&((t=(s=buf)+fread(buf,1,str,stdin))==s)?EOF:(*s++);}

inline int getint ()
{
	register int x = 0; register char c = gc(); register bool m = 0;
	while (!isdigit(c) && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
	if (m) return -x;
	else return x;
}

ll a[maxn], b[maxn];

inline void nico_get (int pos)
{
	register ll x = 0, y = 0; register char c = gc();  register bool m = 0;
	while (!isdigit(c) && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (isdigit(c)) x = ((x << 3) + (x << 1) + c - '0') % mod1, y = ((y << 3) + (y << 1) + c - '0') % mod2, c = gc();
	if (m) a[pos] = -x, b[pos] = -y;
	else a[pos] = x, b[pos] = y;
}

int n, m;

priority_queue <int, vector <int>, greater <int> > nico_ans;

inline ll nico_work (int x, ll *data, int modn)
{
	register long long ret = data[n];
	for (rint i = n-1; i >= 0; i --) ret = (ret * x + data[i]) % modn;
	return ret;
}

int main ()
{
	//freopen ("nico.in","r",stdin);
	//freopen ("nico.out","w",stdout);
	n = getint (), m = getint ();
	for (rint i = 0; i <= n; i ++) nico_get (i);
	for (rint i = 1; i <= m && i <= mod1; i ++)
	{
		if (nico_work (i, a, mod1) == 0ll)
		{
			for (rint j = i; j <= m; j += mod1)
			{
				if (nico_work (j, b, mod2) == 0ll) nico_ans.push (j);
			}
		}
	}
	
	printf ("%d\n", nico_ans.size());
	while (!nico_ans.empty()) printf ("%d\n", nico_ans.top()), nico_ans.pop ();
	
	return 0;
}
