

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

inline const int& minn (const int& x,const int& y) {return x<y? x:y;}

struct node {
	int a, b, m, id;
	bool flag;
} dat[1001];
int ans[1001], order[1001];
inline bool cmp (node aa, node bb) {return aa.m < bb.m;}

int main ()
{
	register int n, h, t;
	cin >> n;
	for (rint i = 1; i <= n; i ++) cin >> dat[i].a, dat[i].id = i;
	for (rint i = 1; i <= n; i ++) {
		cin >> dat[i].b, dat[i].m = minn (dat[i].a, dat[i].b), dat[i].flag = dat[i].m==dat[i].a? true:false;
	}
	std::sort (dat+1, dat+n+1, cmp);
	h = 0, t = n+1;
	for (rint i = 1; i <= n; i ++)
	{
		if (dat[i].flag) order[++ h] = i, ans[h] = dat[i].id;
		else order[-- t] = i, ans[t] = dat[i].id;
	}
	h = t = 0;
	for (rint i = 1; i <= n; i ++)
	{
		h += dat[order[i]].a;
		if (t < h) t = h;
		t += dat[order[i]].b;
	}
	cout << t << endl;
	//for (rint i = 1; i <= n; i ++) cout << ans[i] << " ";
	return 0;
}
