#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")

#include <stdio.h>
#include <string.h>

#define maxn 10001
#define maxm 100001
#define maxl 51
#define suml 5000001
#define rint register int

int n, m, pt;
char name[maxl];

struct node {
	int son[26];
	bool flag, vis;
} trie[suml];

inline void insert (char s[])
{
	register int now = 0, len = strlen (s), val;
	for (rint i = 0; i < len; i ++)
	{
		val = s[i] - 'a';
		if (!trie[now].son[val]) trie[now].son[val] = ++pt;
		now = trie[now].son[val];
	}
	trie[now].flag = true;
}

inline short find (char s[])
{
	register int len = strlen(s), now = 0, val;
	for (rint i = 0; i < len; i ++)
	{
		val = s[i] - 'a';
		if (!trie[now].son[val]) return 3;
		now = trie[now].son[val];
	}
	if (!trie[now].flag) return 3;
	if (!trie[now].vis)
	{
		trie[now].vis = true;
		return 1;
	}
	return 2;
}

int main ()
{
	scanf ("%d", &n);
	for (rint i = 1; i <= n; i ++)
	{
		scanf ("%s", name);
		insert (name);
	}
	scanf ("%d", &m);
	register int ret;
	for (rint i = 1; i <= m; i ++)
	{
		scanf ("%s", name);
		ret = find (name);
		if (ret == 1) puts ("OK");
		else if (ret == 2) puts ("REPEAT");
		else puts ("WRONG");
	}
	return 0;
}
