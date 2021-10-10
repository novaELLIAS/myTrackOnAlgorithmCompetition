#pragma GCC optimize ("Ofast", 3)
#pragma G++ optimize ("Ofast", 3)

#include <stdio.h>

#define maxn 500001

struct node
{
	int father, ch[2];
	int val, cnt, son;
} data[maxn];

int n, root, tot;

inline void update (int u) { data[u].son = data[data[u].ch[0]].son + data[data[u].ch[1]].son + data[u].cnt; }

inline void rotate (int x)
{
	register int y = data[x].father;
	register int z = data[y].father;
	register int k = data[y].ch[1] == x;
	data[z].ch[data[z].ch[1] == y] = x;
	data[x].father = z;
	data[y].ch[k] = data[x].ch[k^1];
	data[data[x].ch[k^1]].father = y;
	data[x].ch[k^1] = y;
	data[y].father = x;
	update (y);
	update (x);
}

inline void splay (int x, int to)
{
	while (data[x].father != to)
	{
		int y = data[x].father;
		int z= data[y].father;
		if (z != to) ( data[y].ch[0] == x)^( data[z].ch[0] == y)? rotate (x):rotate (y);
		rotate (x);
	}
	if (to == 0) root = x;
}

inline void insert (int x)
{
	int u = root, fpos = 0;
	while (u && data[u].val != x)
	{
		fpos = u;
		u = data[u].ch[x > data[u].val];
	}
	if(u) data[u].cnt ++;
	else {
		u = ++ tot;
		if (fpos) data[fpos].ch[x > data[fpos].val] = u;
		data[tot].ch[0] = 0;
		data[tot].ch[1] = 0;
		data[tot].father = fpos;
		data[tot].val = x;
		data[tot].cnt = 1;
		data[tot].son = 1;
	}
	
	splay (u, 0);
}

inline void find (int x)
{
	int u = root;
	if (!u) return;
	while (data[u].ch[x > data[u].val] && x != data[u].val) u = data[u].ch[x > data[u].val];
	splay (u, 0);
}

inline int next (int x, int f)
{
	find (x);
	int u = root;
	if ((data[u].val > x && f) || (data[u].val < x && !f)) return u;
	u = data[u].ch[f];
	while (data[u].ch[f^1]) u = data[u].ch[f^1];
	return u;
}

inline void pop (int x)
{
	register int last = next (x, 0);
	register int neet = next (x, 1);
	splay (last, 0);
	splay (neet, last);
	register int pos = data[neet].ch[0];
	if (data[pos].cnt > 1)
	{
		data[pos].cnt --;
		splay (pos, 0);
	} else data[neet].ch[0] = 0;
}

inline int find_th (int x)
{
	register int u = root;
	if (data[u].son < x) return false;
	register int y;
	while (true)
	{
		y = data[u].ch[0];
		if (x > data[y].son + data[u].cnt)
		{
			x -= data[y].son + data[u].cnt;
			u = data[u].ch[1];
		} else if (data[y].son >= x) u = y;
		else return data[u].val;
	}
}

inline int fastread ()
{
	int sign = 1, n = 0;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar ();
	if (c == '-') sign = -1, c = getchar ();
	while (c >= '0' && c <= '9')
	{
		n = (n << 3) + (n << 1) + c-'0';
		c = getchar();
	}
	return sign*n;
}

int main()
{
	n = fastread ();
	
	insert (-0x7ffffff);
	insert (0x7ffffff);
	
	int opri, num;
	
	while (n --)
	{
		opri = fastread();
		switch (opri)
		{
			case 1: insert (fastread ()); break;
			case 2: pop (fastread ()); break;
			case 3:
				find (fastread ());
				printf ("%d\n", data[data[root].ch[0]].son);
				break;
			case 4: printf ("%d\n", find_th (fastread () + 1)); break;
			case 5: printf ("%d\n", data[next (fastread (), 0)].val); break;
			case 6: printf ("%d\n", data[next (fastread (), 1)].val); break;
		}
	}
	return 0;
}
