#pragma G++ Optimize ("Ofast", 3)

#include <cstdio>

#define stack_size (20001000)
int stack[stack_size],bak;

static char buf[1<<14],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc(); register bool m = 0;
	while ((c<'0'||c>'9') && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}

inline const int& max (const int& a, const int& b) {return a>b? a:b;}

#define maxd 31
#define Re register
#define maxn 100001

struct star_node {
	int to, va, nxt;
} e[maxn<<1];
int head[maxn], ecnt, cnt, s[maxn];

struct trie_node {
	int son[2];
} trie[maxn<<5];

inline void insert (register int x)
{
	register int pos = 0;
	register bool ch;
	for (Re int i = maxd; ~i; -- i)
	{
		ch = x & (1 << i);
		if (!trie[pos].son[ch]) trie[pos].son[ch] = ++ cnt;
		pos = trie[pos].son[ch];
	}
}

static void xor_dfs (int x, int las, int sum)
{
	register int to, va; s[x] = sum;
	for (Re int i = head[x]; i; i = e[i].nxt)
	{
		to = e[i].to, va = e[i].va;
		if (to ^ las)
		{
			insert (sum ^ va);
			xor_dfs (to, x, sum ^ va);
		}
	}
}

inline int query (register int x)
{
	register int ret = 0, pos = 0;
	register bool ch;
	for (Re int i = maxd; ~i; -- i)
	{
		ch = x & (1 << i);
		if (trie[pos].son[!ch])
		{
			pos = trie[pos].son[!ch];
			ret += 1 << i;
		} else pos = trie[pos].son[ch];
	}
	return ret;
}

int main ()
{
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out","w",stdout);
	
	__asm__ __volatile__  
    (  
        "mov %%esp,%0\n" 
        "mov %1,%%esp\n" 
        :"=g"(bak)  
        :"g"(stack+stack_size-1)  
        :  
    );  
	
	register int n = read (), fr, to, va, ans = 0;
	for (Re int i = 1; i < n; ++ i)
	{
		fr = read (), to = read (), va = read ();
		e[++ ecnt] = (star_node) {to, va, head[fr]}, head[fr] = ecnt;
		e[++ ecnt] = (star_node) {fr, va, head[to]}, head[to] = ecnt;
	}
	xor_dfs (1, 0, 0);
	for (Re int i = 1; i <= n; ++ i) ans = max (ans, query(s[i]));
	printf ("%d", ans);
	fclose (stdin), fclose (stdout);
	return 0;
}
