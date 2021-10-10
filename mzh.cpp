#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

#define maxl 2000101
#define Re register

struct tree {
	int fail, nxt[26], end, ans;
} aca[maxl];

int cnt = 1, psi[maxl], tim[maxl];
char in[25], s[10001][25];

inline void build_trie (char s[], int pss)
{
	register int len = strlen(s);
	register int now = 0;
	for (Re int i = 0; i ^ len; i ++)
	{
		if (aca[now].nxt[s[i]^'a'] == 0)
		{
			aca[now].nxt[s[i]^'a'] = ++ cnt;
		}
		now = aca[now].nxt[s[i]^'a'];
	}
	++ aca[now].end, psi[pss] = now;
}

inline void get_fail ()
{
	queue <int> nico; nico.push (0);
	register int fr, to;
	while (!nico.empty())
	{
		fr = nico.front(), nico.pop();
		for (Re int i = 0; i ^ 26; ++ i)
		{
			if (aca[fr].nxt[i])
			{
				if (!fr) aca[aca[fr].nxt[i]].fail = 0;
				else {
					to = aca[fr].fail;
					while (to ^ (-1))
					{
						if (aca[to].nxt[i])
						{
							aca[aca[fr].nxt[i]].fail = aca[to].nxt[i];
							break;
						}
						to = aca[to].fail;
					}
					if (to == -1) aca[aca[fr].nxt[i]].fail = 0;
				}
				nico.push (aca[fr].nxt[i]);
			}
		}
	}
}

inline void niconi (int now, int pss)
{
	//puts ("query niconi");
	while (now ^ (-1))
	{
		if (aca[now].end && tim[now] < pss) ++ aca[now].ans;
		tim[now] = pss, now = aca[now].fail;
	}
}

inline void aca_query (char s[], int pss)
{
	register int len = strlen(s);
	register int now = 0, pos = 0;
	for (Re int i = 0; i ^ len; ++ i)
	{
		if (aca[now].nxt[s[i]^'a']) now = aca[now].nxt[s[i]^'a'];
		else {
			pos = aca[now].fail;
			while ((pos^(-1)) && !aca[pos].nxt[s[i]^'a']) pos = aca[pos].fail;
			if (pos == -1) now = 0;
			else now = aca[pos].nxt[s[i]^'a'];
		}
		//puts ("aca query");
		niconi (now, pss);
	}
}

int main ()
{
	freopen ("mzh.in", "r", stdin);
	freopen ("mzh.out","w",stdout);
	
	aca[0].fail = -1;
	register int n; scanf ("%d", &n);
	for (Re int i = 1; i <= n; ++ i) scanf ("%s", s[i]);
	
	//puts ("niconi");
	
	register int m; scanf ("%d", &m);
	for (Re int i = 1; i <= m; ++ i)
	{
		scanf("%s", in);
		build_trie (in, i);
	}
	
	//puts ("niconiconi");
	
	get_fail();

	//puts ("niconiconiconi");
	
	for (Re int i = 1; i <= n; ++ i) aca_query (s[i], i);
	
	for (Re int i = 1; i <= m; ++ i) printf ("%d\n", aca[psi[i]].ans);
	
	fclose (stdin), fclose (stdout);
	
	return 0;
}
