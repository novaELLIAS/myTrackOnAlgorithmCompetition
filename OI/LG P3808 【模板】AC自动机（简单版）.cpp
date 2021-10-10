#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

#define maxl 1000000

struct tree {
	int fail;
	int next[26];
	int end;
} aca[maxl];

int n, cnt;
char in[maxl];

inline void build_trie (char s[])
{
	int len = strlen(s);
	int now = 0;
	for (int i = 0; i < len; i ++)
	{
		if (aca[now].next[s[i]-'a'] == 0)
		{
			aca[now].next[s[i]-'a'] = ++cnt;
		}
		now = aca[now].next[s[i]-'a'];
	}
	aca[now].end ++;
}

inline void get_fail ()
{
	queue <int> nico;
	
	for (int i = 0; i < 26; i ++)
	{
		if (aca[0].next[i] != 0)
		{
			aca[aca[0].next[i]].fail = 0;
			nico.push(aca[0].next[i]);
		}
	}
	
	int fro;
	while (!nico.empty())
	{
		fro = nico.front();
		nico.pop();
		
		for (int i = 0; i < 26; i ++)
		{
			if (aca[fro].next[i] != 0)
			{
				aca[aca[fro].next[i]].fail = aca[aca[fro].fail].next[i];
				nico.push(aca[fro].next[i]);
			} else {
				aca[fro].next[i] = aca[aca[fro].fail].next[i];
			}
		}
	}
}

inline int aca_query (char s[])
{
	int len = strlen(s);
	int now = 0, ret = 0;
	for (int i = 0; i < len; i ++)
	{
		now = aca[now].next[s[i]-'a'];
		for (int j = now; j && aca[j].end != -1; j = aca[j].fail)
		{
			ret += aca[j].end;
			aca[j].end = -1;
		}
	}
	return ret;
}

int main ()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%s", in);
		build_trie(in);
	}
	
	get_fail();
	
	scanf("%s", in);
	printf("%d", aca_query(in));
	return 0;
}
