#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>

namespace fastIO {
    const int str=1<<20;
    const char* endll="\n";
    struct Reader {
        char buf[str],*s,*t;
        bool EOF_FLG;
        Reader():s(buf),t(buf),EOF_FLG(false) {};
        inline char gt() {
            return s==t&&((t=(s=buf)+fread(buf,1,str,stdin))==s)?EOF:(*s++);
        }
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
        char buf[str],*s,*t;
        Writer():s(buf),t(buf+str) {}
        ~Writer() {
            fwrite(buf,1,s-buf,stdout);
        }
        inline void pt(char c) {
            (s==t)?(fwrite(s=buf,1,str,stdout),*s++=c):(*s++=c);
        }
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

using namespace fastIO;
using namespace std;

#define maxn 50001
#define rint register int
#define ll long long

struct node {
	int id, l, r, b;
	bool operator < (const node x) const {return b==x.b? b&1?r<x.r:r>x.r:b<x.b;}
} a[maxn];
int blo[maxn], sqr, col[maxn], n, m;
unsigned sum[maxn], cnt;

struct anss {
	unsigned l, r;
} out[maxn];

int main ()
{
	#ifndef ONLINE_JUDGE
		freopen ("nico.in","r",stdin);
		freopen ("nico.out","w",stdout);
	#endif
	fastIO::cin >> n >> m;
	sqr = sqrt (n);
	for (rint i = 1; i <= n; i ++) fastIO::cin >> col[i];
	for (rint i = 1; i <= m; i ++) fastIO::cin >> a[i].l >> a[i].r, a[i].id = i, a[i].b=a[i].l/sqr;
	std::sort (a+1, a+m+1);
	register int l, r, id, L = a[1].l, R = a[1].l-1;
	register unsigned k, s;
	for (rint i = 1; i <= m; i ++)
	{
		l = a[i].l, r = a[i].r, id = a[i].id;
		
		while (L < l) cnt -= -- sum[col[L ++]];
		while (L > l) cnt += sum[col[-- L]] ++;
		while (R < r) cnt += sum[col[++ R]] ++;
		while (R > r) cnt -= -- sum[col[R --]];
		
		cnt? out[id].l = cnt/(k=__gcd(cnt,s=(unsigned)(r-l+1)*(r-l)>>1)), out[id].r = s/k:(out[id].l = 0, out[id].r = 1);
	}
	for (rint i = 1; i <= m; i ++) cout << out[i].l << "/" << out[i].r << endll;
	return 0;
} 
