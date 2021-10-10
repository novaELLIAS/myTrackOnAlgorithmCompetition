#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")

#include <cstdio>
#include <algorithm>

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc() {
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read () {
	register int x = 0; register char c = gc();
	while ((c < '0' || c > '9')) c = gc();
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return x;
}
static void write (int x) {
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (int x) {if(x<0)x=-x,putchar('-'); write (x); putchar ('\n');}

inline const int& max (const int& a, const int& b) {return a>b? a:b;}
inline const int& min (const int& a, const int& b) {return a<b? a:b;}
#define abs(x) ((x)<0? -(x):(x))

typedef long long ll;
#define maxn 150001

struct node {
	int x, y, wei, exp;
} dat[maxn];
inline bool cmp (node a, node b) {return a.y < b.y;}

signed main ()
{
	readin:
	read(), read();
	register int t = read (), k = read () + 1;
	for (register int i = 1; i ^ k; ++ i) {
		dat[i].x = read(), dat[i].y = read(),
		dat[i].wei = dat[i].exp = read();
	};
	
	init:
	std::sort (dat + 1, dat + k, cmp);
	
	alchemy:
	for (register int i = 1; i ^ k; ++ i) {
		for (register int j = 1; j ^ i; ++ j) {
			if (t * abs(dat[i].y - dat[j].y) >= abs(dat[i].x - dat[j].x)) {
				dat[i].exp = max (dat[i].exp, dat[j].exp + dat[i].wei);
			}
		}
	}
	
	outoput:
	register int ans = -1;
	for (register int i = 1; i <= k; ++ i) ans = max (ans, dat[i].exp);
	return write (ans), 0;
}
