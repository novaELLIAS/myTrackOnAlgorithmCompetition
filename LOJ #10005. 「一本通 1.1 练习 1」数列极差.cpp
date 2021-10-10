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
#include <ext/pb_ds/priority_queue.hpp> 

namespace fastIO {
    const int str = 1<<20; const char* endl = "\n";
    struct Reader {
        char buf[str], *s, *t;
        bool EOF_FLG;
        Reader():s(buf), t(buf), EOF_FLG(false) {};
        inline char gt() {
            return s==t&&((t=(s=buf)+fread(buf,1,str,stdin))==s)?EOF:(*s++);
        }
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
using namespace __gnu_pbds;

struct cmpmin {
    inline bool operator() (const int& aa, const int& bb) {
        return aa < bb;
    }
};

struct cmpmax {
	inline bool operator() (const int&aa, const int& bb) {
		return aa > bb;
	}
};

__gnu_pbds::priority_queue <int, cmpmax, pairing_heap_tag> xmax;
__gnu_pbds::priority_queue <int, cmpmin, pairing_heap_tag> xmin;

int main ()
{
	register int n, in, nn;
	cin >> n, nn = n - 1;
	while (n --) {
		cin >> in, xmax.push (in), xmin.push (in);
	}
	cin >> in;
	register int a, b;
	while (nn --) {
		a = xmax.top (), xmax.pop (), b = xmax.top (), xmax.pop ();
		xmax.push (a * b + 1);
		a = xmin.top (), xmin.pop (), b = xmin.top (), xmin.pop ();
		xmin.push (a * b + 1);
	}
	cout << xmax.top () - xmin.top ();
	return 0;
}
