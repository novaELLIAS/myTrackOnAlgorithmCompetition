#prag\
ma GCC optimize ("Ofast", 3)
#prag\
ma G++ optimize ("Ofast", 3)

#include <cstdio>
#include <map>

using namespace std;

#define rint register int
#define swap(x,y) ((y)^=(x)^=(y)^=(x))
#define gc() getchar()

struct StandNode
{
	bool a[16];

	inline int get_hash ()
	{
		register int ret = a[0];
		for (rint i = 1; i <= 15; i ++) ret = (ret<<1) + a[i];
		return ret;
	}
	inline int get_dif_fir (StandNode cmp)
	{
		for (rint i = 0; i <= 15; i ++) if ((a[i]^cmp.a[i]) && cmp.a[i]) return i;
		return -1;
	}
	inline bool cmp (StandNode fr)
	{
		for (rint i = 0; i <= 15; i ++) if (a[i]^fr.a[i]) return false;
		return true;
	}
} nico_STA, nico_FIN;

struct QueueNode
{
	StandNode a;
	int ste;
} que[65537];

inline void input ()
{
	register char c[5];
	register int pos = 0;
	for (rint t = 1; t <= 4; t ++)
	{
		scanf ("%s", c);
		for (rint i = 0; i <= 3; i ++) nico_STA.a[pos ++] = c[i] - '0';
	}
	pos = 0;
	for (rint t = 1; t <= 4; t ++)
	{
		scanf ("%s", c);
		for (rint i = 0; i <= 3; i ++) nico_FIN.a[pos ++] = c[i] - '0';
	}
}

map <int, bool> sjb;

inline void nico_bfswork (register int diff, register int xpos, register int head, register int &tail)
{
	register StandNode ellias; register int kiana;
	if (xpos && !que[head].a.a[diff - 1])
	{
		ellias = que[head].a, swap (ellias.a[diff], ellias.a[diff - 1]);
		kiana = ellias.get_hash ();
		if (!sjb[kiana]) que[++ tail].a = ellias, que[tail].ste = que[head].ste + 1, sjb[kiana] = true;
	}
	if (xpos <= 2 && !que[head].a.a[diff + 1])
	{
		ellias = que[head].a, swap (ellias.a[diff], ellias.a[diff + 1]);
		kiana = ellias.get_hash ();
		if (!sjb[kiana]) que[++ tail].a = ellias, que[tail].ste = que[head].ste + 1, sjb[kiana] = true;
	}
	if (diff >= 4 && !que[head].a.a[diff - 4])
	{
		ellias = que[head].a, swap (ellias.a[diff], ellias.a[diff - 4]);
		kiana = ellias.get_hash ();
		if (!sjb[kiana]) que[++ tail].a = ellias, que[tail].ste = que[head].ste + 1, sjb[kiana] = true;
	}
	if (diff <= 11 && !que[head].a.a[diff + 4])
	{
		ellias = que[head].a, swap (ellias.a[diff], ellias.a[diff + 4]);
		kiana = ellias.get_hash ();
		if (!sjb[kiana]) que[++ tail].a = ellias, que[tail].ste = que[head].ste + 1, sjb[kiana] = true;
	}
}

int main ()
{
	input ();
	int FIN = nico_FIN.get_hash();

	register int head = 0, tail = 1, diff, xpos, kiana;
	que[tail].a = nico_STA;
	sjb[nico_STA.get_hash()] = true;
	while (head < tail)
	{
		head ++;
		if (que[head].a.get_hash() == FIN)
		{
			printf ("%d", que[head].ste);
			return 0;
		}
		for (rint i = 0; i <= 15; i ++) nico_bfswork (i, i % 4, head, tail);
	}
	puts ("No Solution");
	return 0;
}
