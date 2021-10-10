#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")

#include <stdio.h>
#include <ctype.h>

inline char gc() {
	static char buf[1<<14],*p1=buf,*p2=buf;
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}

inline int read () {
	register int x = 0;register char c = gc();
	while (!isdigit(c)) c = gc();
	while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
	return x;
}

int nico[100001];

#define lowbit(x) x&-x

inline void update(int pos, int num)
{
	while(pos <= 100001) {
		nico[pos] += num;
		pos += lowbit(pos);
	}
}
inline int query(int pos)
{
	int ret = 0;
	while(pos) {
		ret += nico[pos];
		pos -= lowbit(pos);
	}
	return ret;
}

int main ()
{
	register int n = read(), m = read(), x, y;
	while (m --)
	{
		if (read() == 1) update (read(), 1), update (read()+1, -1);
		else printf ("%d\n", query (read()) % 2);
	}
	return 0;
}
