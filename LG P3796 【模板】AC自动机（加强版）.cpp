#prag\
ma GCC optimize ("Ofast")

#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define maxl 1000000
#define maxn 152

struct trie
{
	int fail;
	int next[26];
	int end;
} aca[maxl];
struct node
{
	int num;
	int pos;
} bol[maxn];

int n, cnt, p;
char in[maxn][maxl];

inline bool cmp (node a, node b)
{
	if (a.num == b.num) return a.pos < b.pos;
	else return a.num > b.num;
}
inline void reset (int x)
{
	memset (aca[x].next, 0, sizeof aca[x].next);
	aca[x].fail = 0;
	aca[x].end = 0;
}
inline void build_trie (char s[], int x)
{
	int len = strlen(s);
	int now = 0;
	for (int i = 0; i < len; i ++)
	{
		if (aca[now].next[s[i]-'a'] == 0)
		{
			aca[now].next[s[i]-'a'] = ++cnt;
			reset(cnt);
		}
		now = aca[now].next[s[i]-'a'];
	}
	aca[now].end = x;
}
inline void get_fail ()
{
	queue <int> nico;
	int fro;
	for (int i = 0; i < 26; i ++)
	{
		if (aca[0].next[i] != 0)
		{
			aca[aca[0].next[i]].fail = 0;
			nico.push(aca[0].next[i]);
		}
	}
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
	int now = 0;
	for (int i = 0; i < len; i ++)
	{
		now = aca[now].next[s[i]-'a'];
		for (int j = now; j ; j = aca[j].fail)
		{
			bol[aca[j].end].num ++;
		}
	}
}
int main ()
{
	while (true)
	{
		scanf("%d", &n);
		if (n == 0) return 0;
		cnt = 0;
		reset(0);
		
		for (int i = 1; i <= n; i ++)
		{
			scanf("%s", in[i]);
			bol[i].num = 0;
			bol[i].pos = i;
			build_trie (in[i], i);
		}
		
		get_fail();
		
		scanf("%s", in[0]);
		aca_query(in[0]);
		sort(bol+1, bol+n+1, cmp);
		
		printf("%d\n%s\n", bol[1].num, in[bol[1].pos]);
		for (int i = 2; i <= n; i ++)
		{
			if (bol[i].num == bol[i-1].num)
			{
				puts(in[bol[i].pos]);
			} else break;
		}
	}
	return 0;
}
