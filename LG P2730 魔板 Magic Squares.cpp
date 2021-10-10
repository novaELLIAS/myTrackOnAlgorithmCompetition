#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")

#include <cstdio>
#include <cctype>
#include <map>

namespace fastIO {
    const int str=1<<20;
    const char* kiana="\n";
    struct Reader {
        char buf[str],*s,*t;
        bool EOF_FLG;
        Reader():s(buf),t(buf),EOF_FLG(false) {};
        inline char gt() {
            return s==t&&((t=(s=buf)+fread(buf,1,str,stdin))==s)?EOF:(*s++);
        }
        #define gt() getchar ()
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
using namespace std;

#define rint register int
#define swap(x,y) y^=x^=y^=x

int STA[8] = {1, 2, 3, 4, 8, 7, 6, 5};

struct nico {
	int a[8];
	inline void set (int *fr)
	{
		for (rint i = 0; i <= 7; i ++) a[i] = fr[i];
	}
	inline int hash ()
	{
		register int ret = a[0];
		for (rint i = 1; i <= 7; i ++) ret = (ret<<3) + a[i];
		return ret;
	}
	inline bool cmp (nico bb)
	{
		for (rint i = 0; i <= 7; i ++)
		{
			if (a[i] != bb.a[i]) return false;
		}
		return true;
	}
} nico_NULL, nico_FIN, nico_STA;

struct node {
	nico a;
	int ste, fa;
	char c;
} que[500001];

map <int, bool> sjb;

inline nico nico_A (nico fr)
{
	register nico ret = nico_NULL;
	for (rint i = 0; i <= 3; i ++) {
		ret.a[i] = fr.a[i+4], ret.a[i+4] = fr.a[i];
	}
	return ret;
}

inline nico nico_B (nico fr)
{
	register nico ret = nico_NULL;
	ret.a[0] = fr.a[3], ret.a[1] = fr.a[0], ret.a[2] = fr.a[1], ret.a[3] = fr.a[2],\
	ret.a[4] = fr.a[7], ret.a[5] = fr.a[4], ret.a[6] = fr.a[5], ret.a[7] = fr.a[6];
	return ret;
}

inline nico nico_C (nico fr)
{
	register nico ret = fr;
	ret.a[1] = fr.a[5], ret.a[2] = fr.a[1], ret.a[5] = fr.a[6], ret.a[6] = fr.a[2];
	return ret;
}

inline void input ()
{
	register int in[8]; for (rint i = 0; i <= 7; i ++) cin >> in[i];
	/*nico_FIN.set (in); */nico_STA.set (STA);
	nico_FIN.a[0] = in[0], nico_FIN.a[1] = in[1], nico_FIN.a[2] = in[2], nico_FIN.a[3] = in[3],\
	nico_FIN.a[4] = in[7], nico_FIN.a[5] = in[6], nico_FIN.a[6] = in[5], nico_FIN.a[7] = in[4];
}

inline void nico_print (node x)
{
	register int pos = 0;
	register char c[500001];
	while (x.fa) c[++ pos] = x.c, x = que[x.fa];
	register int cnt = 0;
	for (rint i = pos; i; i --)
	{
		putchar (c[i]);
		if (!((++cnt)%60)) putchar ('\n');
	}
}

int main ()
{
	input ();
	
	register int head = 0, tail = 1, hasn;
	register nico ellias;
	que[1].ste = que[1].fa = 0, que[1].a = nico_STA;
	sjb[nico_STA.hash()] = true;
	while (head < tail)
	{
		head ++;
		if (nico_FIN.cmp (que[head].a)) {cout << que[head].ste << kiana; nico_print (que[head]); return 0;}
		//puts ("check fin");
		ellias = nico_A (que[head].a);
		hasn = ellias.hash();
		if (!sjb[hasn]) sjb[hasn] = true, tail ++, que[tail].a = ellias, que[tail].ste = que[head].ste + 1, que[tail].fa = head, que[tail].c = 'A';
		//puts ("check A");
		ellias = nico_B (que[head].a);
		hasn = ellias.hash();
		if (!sjb[hasn]) sjb[hasn] = true, tail ++, que[tail].a = ellias, que[tail].ste = que[head].ste + 1, que[tail].fa = head, que[tail].c = 'B';
		//puts ("check B");
		ellias = nico_C (que[head].a);
		hasn = ellias.hash();
		if (!sjb[hasn]) sjb[hasn] = true, tail ++, que[tail].a = ellias, que[tail].ste = que[head].ste + 1, que[tail].fa = head, que[tail].c = 'C';
		//puts ("check C");
	}
	
	putchar ('0');
	return 0;
}
