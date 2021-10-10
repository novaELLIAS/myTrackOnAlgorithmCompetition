#include <stdio.h>
#include <ctype.h>
#include <ext/pb_ds/priority_queue.hpp>

namespace fastIO {
	const int str=1<<20;
	const char* kiana="\n";
	bool EOF_FLG;
	struct Reader {
		#define gt() getchar() 
		template<typename T>Reader&operator>>(T&x) {
			if(EOF_FLG)return *this;
			register char c=0,d;
			while(c!=EOF&&!isdigit(c))d=c,c=gt();
			if(c==EOF) {
				EOF_FLG=true;
				return *this;
			} else x=0;
			while(isdigit(c))x=(x<<3)+(x<<1)+c-'0',c=gt();
			if(d=='-')x=-x;
			return *this;
		}
	} cin;
	struct Writer {
		#define pt(c) putchar(c)
		template<typename T>Writer&operator<<(T x) {
			if(!x)return pt('0'),*this;
			if(x<0)pt('-'),x=-x;
			register char a[30],t=0;
			while(x)a[t++]=x%10,x/=10;
			while(t--)pt(a[t]+'0');
			return *this;
		}
		Writer&operator<<(const char*s) {
			while(*s)pt(*s++);
			return *this;
		}
	} cout;
}

using namespace std;
using namespace fastIO;
using namespace __gnu_pbds;

#define maxn 100001
#define rint register int

__gnu_pbds::priority_queue <int, less <int>, binomial_heap_tag> nico[maxn];
int fa[maxn];

inline int find (int x)
{
	while (x != fa[x]) x = fa[x] = fa[fa[x]];
	return x;
}

int main ()
{
	register int n, m, in, x, y, mx, my;
	while (scanf ("%d", &n) != EOF)
	{
		for (rint i = 1; i <= n; i ++) {
			fa[i] = i; nico[i].clear();
			fastIO::cin >> in; nico[i].push (in);
		}
		fastIO::cin >> m;
		while (m --) {
			fastIO::cin >> x >> y;
			x = find (x), y = find (y);
			if (x == y) puts ("-1");
			else {
				mx = nico[x].top(), nico[x].pop(), nico[x].push(mx>>1);
				my = nico[y].top(), nico[y].pop(), nico[y].push(my>>1);
				fa[x] = y; nico[y].join (nico[x]);
				cout << nico[y].top() << kiana;
			}
		}
	}
	return 0;
}
