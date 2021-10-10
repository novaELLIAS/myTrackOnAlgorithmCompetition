#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")

#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

#define Re register
#define maxn 400005

int son[maxn][10], cnt;
bool vis[maxn];

inline bool nico_insert (char s[])
{
	register int len = strlen (s), dat, rot = 0;
	register bool flag = false;
	for (Re int i = 0; i ^ len; ++ i)
	{
		dat = s[i] ^ '0';
		if (!son[rot][dat]) son[rot][dat] = ++ cnt;
		else if (!(i ^ (len - 1))) flag = true;
		rot = son[rot][dat]; if (vis[rot]) flag = true;
	}
	vis[rot] = true; return flag;
}

int main ()
{
	register char str[maxn];
	register int _, n; scanf ("%d", &_);
	register bool flag = false;
	while (_ --)
	{
		memset (son, 0, sizeof son);
		memset (vis, 0, sizeof vis);
		scanf ("%d", &n); flag = false, cnt = 0;
		for (Re int i = 0; i ^ n; i ++)
		{
			scanf ("%s", str);
			if (flag || nico_insert (str)) flag = true;
		}
		puts (flag? "NO":"YES");
	}
	return 0;
}
