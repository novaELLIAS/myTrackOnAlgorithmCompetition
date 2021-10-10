#pragma G++ optimize (3)

#include <cstdio>
#include <set>
#include <algorithm>

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
    return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc(); //register bool m = false;
	while ((c < '0' || c > '9')/* && (c ^ '-')*/) c = gc();
	//if (c == '-') m = true, c = gc ();
	while (c>='0'&&c<='9') x = (x<<3) + (x<<1) + (c^'0'), c = gc();
	return x;
}

#define Re register

using std::multiset;
using std::sort;
using std::pair;
using std::lower_bound;

using namespace std;
multiset <int> st;
multiset <int> :: iterator ps;
pair <int, int> grs[100001], cow[100001];

signed main ()
{
	register int n = read (), m = read ();
	for (Re int i = 1; i <= n; ++ i) cow[i].second = read (), cow[i].first = -read ();
	for (Re int i = 1; i <= m; ++ i) grs[i].second = read (), grs[i].first = -read ();
	sort (cow + 1, cow + n + 1), sort (grs + 1, grs + m + 1);
	register long long ans = 0ll;
	for (Re int i = 1, j = 1; i <= n; ++ i)
	{
		while (j <= m && cow[i].first >= grs[j].first)
			st.insert (grs[j].second), ++ j;
		ps = st.lower_bound(cow[i].second);
		if (ps == st.end ()) return printf ("-1"), 0;
		ans += *ps, st.erase (ps);
	}
	return printf ("%lld", ans), 0;
}
