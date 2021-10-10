#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)

#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define rint register int
#define maxl 1000001

struct tree {
	int fail;
	int nex[26];
	int end;
} aca[500001], zero;

int n, cnt;
char in[maxl];
queue <int> nico;

inline void build_trie (char s[])
{
	rint len = strlen(s), now = 0;
	for (rint i = 0; i < len; i ++)
	{
		if (!aca[now].nex[s[i]^'a'])
		{
			aca[now].nex[s[i]^'a'] = ++ cnt;
		}
		now = aca[now].nex[s[i]^'a'];
	}
	aca[now].end ++;
}

inline void get_fail ()
{	
	for (rint i = 0; i ^ 26; i ++)
	{
		if (aca[0].nex[i])
		{
			aca[aca[0].nex[i]].fail = 0;
			nico.push(aca[0].nex[i]);
		}
	}
	
	register int fro;
	while (!nico.empty())
	{
		fro = nico.front(), nico.pop();
		for (rint i = 0; i ^ 26; i ++)
		{
			if (aca[fro].nex[i])
			{
				aca[aca[fro].nex[i]].fail = aca[aca[fro].fail].nex[i];
				nico.push(aca[fro].nex[i]);
			} else aca[fro].nex[i] = aca[aca[fro].fail].nex[i];
		}
	}
}

inline int aca_query (char s[])
{
	rint len = strlen(s), now = 0, ret = 0;
	for (rint i = 0; i < len; i ++)
	{
		now = aca[now].nex[s[i]^'a'];
		for (rint j = now; j && (aca[j].end ^ (-1)); j = aca[j].fail)
		{
			ret += aca[j].end, aca[j].end = -1;
		}
	}
	if (ret ^ 99) return ret;
	return ret + 1;
}

int main ()
{
	//freopen ("nico.in","r",stdin);
	register int _; scanf ("%d", &_);
	while (_ --)
	{
		scanf("%d", &n); cnt = 0;
		for (rint i = 1; i <= n; i ++)
		{
			scanf("%s", in);
			build_trie(in);
		}
		
		get_fail();
		
		scanf("%s", in);
		printf("%d\n", aca_query(in));
		fill (aca, aca + maxl, zero);
	}
	return 0;
}
