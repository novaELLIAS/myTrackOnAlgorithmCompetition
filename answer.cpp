#pragma G++ optimize (2)
#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

#define Re register
#define maxn 30001
#define maxm 501

string ori[maxn];
map <string, int> sjb;

signed main ()
{
	string tmp = "";
	
	ios::sync_with_stdio(false);
	freopen ("answer.in", "r", stdin);
	freopen ("answer.out","w",stdout);
	
	register int n, m, p, q; cin >> n >> m >> p >> q;
	for (Re int i = 1; i <= n; ++ i) cin >> ori[i], ++ sjb[ori[i]];
	sort (ori + 1, ori + n + 1);
	if (p != 0)
	{
		for (Re int i = 1; i <= n; ++ i)
		{
			if (sjb[ori[i]] == p)
			{
				tmp = "";
				for (Re int j = 0; j < m; ++ j)
					tmp += ori[i][j]=='N'? 'Y':'N';
				if (sjb[tmp] == q) {cout << ori[i]; return 0;}
			}
		}
	} else if (q != 0)
	{
		for (Re int i = n; i; --i)
		{
			if (sjb[ori[i]] == q)
			{
				tmp = "";
				for (Re int j = 0; j < m; ++ j)
					tmp += ori[i][j]=='N'? 'Y':'N';
				if (sjb[tmp] == p) {cout << tmp; return 0;}
			}
		}
	} else {
		register string ac = "", wa = "";
		register int i;
		for (Re int i = 0; i ^ m; ++ i) ac += 'N', wa += 'Y';
		while (true)
		{
			if (!sjb[ac] && !sjb[wa]) {cout << ac; return 0;}
			for (i = m - 1; i >= 0; -- i)
				if (ac[i] == 'N') break;
			if (i == -1)
			{
				putchar('-'), putchar ('1');
				return 0;
			}
			ac[i] = 'Y', wa[i] = 'N';
			for (Re int j = i + 1; j ^ m; ++ j) ac[j] = 'N', wa[j] = 'Y';
		}
	}
	
	putchar ('-'), putchar ('1');
	fclose (stdin), fclose (stdout);
	return 0;
}
