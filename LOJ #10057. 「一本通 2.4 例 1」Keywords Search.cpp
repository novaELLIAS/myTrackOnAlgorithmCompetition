#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)

#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

#define Re register

struct node{
	node *fail, *nxt[26];
	int cnt;
	inline node ()
	{
		for (Re int i = 0; i ^ 26; ++ i) nxt[i] = NULL;
		fail = NULL, cnt = 0;
	}
};

inline void nico_insert (char s[], Re node *rt)
{
	node *p = rt;
	register int len = strlen (s), i = 0, index;
	while (i ^ len)
	{
		index = s[i] ^ 'a';
		if (p -> nxt[index] == NULL) p -> nxt[index] = new node();
		p = p -> nxt[index], ++ i;
	}
	p -> cnt ++;
}

inline void get_fail (node *rt)
{
	register node *p, *tmp;
	queue <node*> que;
	rt -> fail = NULL;
	que.push(rt);
	while (!que.empty())
	{
		p = que.front(), que.pop();
		for (Re int i = 0; i ^ 26; ++ i)
		{
			if (p -> nxt[i] != NULL)
			{
				if (p == rt) p -> nxt[i] -> fail = rt;
				else
				{
					tmp = p -> fail;
					while (tmp -> nxt[i] == NULL && tmp != rt) tmp = tmp -> fail;
					tmp = tmp -> nxt[i], tmp = (tmp == NULL? rt:tmp);
					p -> nxt[i] -> fail = tmp;
				}
				que.push(p -> nxt[i]);
			}
		}
	}
}

inline int ac_query (char s[], Re node *rt)
{
	register node *p = rt, *tmp;
	register int i, len = strlen (s), cnt = 0, index;
	while (i ^ len)
	{
		index = s[i] ^ 'a';
		while (p -> nxt[index] == NULL && p != rt) p = p -> fail;
		p = p -> nxt[index];
		if (p == NULL) p = rt; tmp = p;
		while (tmp != rt && tmp -> cnt != -1)
		{
			cnt += tmp -> cnt;
			tmp -> cnt = -1;
			tmp = tmp -> fail;
		} ++ i;
	}
	return cnt;
}

char s[1000000];

int main()
{
	register int _, n; scanf ("%d", &_);
	while (_ --)
	{
		scanf ("%d", &n);
		Re node *rt = new node ();
		for (Re int i = 0; i ^ n; ++ i) {scanf ("%s", s); nico_insert (s, rt);}
		get_fail(rt);
		scanf ("%s", s);
		printf ("%d\n", ac_query (s,rt));
	}
	return 0;
}

