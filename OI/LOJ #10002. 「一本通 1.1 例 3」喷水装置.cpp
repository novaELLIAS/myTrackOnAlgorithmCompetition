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
#include <math.h>
#include <algorithm>

#define rint register int

namespace fastIO {
    const int str = 1<<20; const char* endl = "\n";
    struct Reader {
        char buf[str], *s, *t;
        bool EOF_FLG;
        Reader():s(buf), t(buf), EOF_FLG(false) {};
        inline char gt() {
            return s==t&&((t=(s=buf)+fread(buf,1,str,stdin))==s)?EOF:(*s++);
    	}
    	//#define gt() getchar ()
        template <typename T> Reader&operator >> (T&x) {
            if (EOF_FLG)return *this;
            register char c=0,d;
            while (c != EOF && (!isdigit(c)))d=c,c=gt();
            if(c == EOF) {
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
        #define pt(c) putchar (c)
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

struct node {
	double sta, end;
} a[15001];
inline bool cmp (node aa, node bb) {return aa.sta < bb.sta;}

int main ()
{
	register int _; cin >> _;
	register int cnt = 0, x, r, n, l, h, ans, i;
	register bool flag;
	register double minr, rr, pos, tmp, dd;
	while (_ --)
	{
		cin >> n >> l >> h;
		minr = (double) h / 2.0, rr, dd = (double)h*h/4.0;
		cnt = ans = 0;
		for (i = 1; i <= n; i ++)
		{
			cin >> x >> r;
			if (r <= minr) continue;
			rr = sqrt (r * r - dd);
			a[++ cnt].sta = (double)x - rr, a[cnt].end = (double)x + rr;
		}
		std::sort (a+1, a+1+cnt, cmp);
		pos = 0.0, i = flag = 1;
		while (pos < l)
		{
			ans ++, tmp = pos;
			for (;a[i].sta <= tmp && i <= cnt; i ++)
				if (pos < a[i].end) pos = a[i].end;
			if (tmp == pos && pos < l) {flag = false; break;}
		}
		if (flag) cout << ans << endl;
		else puts ("-1");
	}
	return 0;
}
