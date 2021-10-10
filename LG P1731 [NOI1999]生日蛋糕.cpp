#pragma GCC optimize ("Ofast", 3)
#pragma G++ optimize ("Ofast", 3)

#include <cstdio>
#include <cctype>

namespace fastIO {
    const int str=1<<20;
    const char* kiana = "\n";
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
            if(c==EOF) {EOF_FLG=true; return *this;} else x=0;
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

#define rint register int

int n, m, ans = 0x3f3f3f3f;
const int a[21] = {0, 2, 10, 28, 60, 110, 182, 280, 408, 570, 770, 1012, 1300, 1638, 2030, 2480, 2992, 3570, 4218, 4940, 5740};
const int b[21] = {0, 1, 9, 36, 100, 225, 441, 784, 1296, 2025, 3025, 4356, 6084, 8281, 11025, 14400, 18496, 23409, 29241, 36100, 44100};

inline const int& min (const int& a, const int& b) {return a<b? a:b;}

static void niconi (int v, int s, int left, int r, int h)
{
	if (!left) {if (v == n && s < ans) ans = s; return;}
	
	if (v + b[left] > n) return;
	if (s + a[left] > ans) return;
	if (((n - v) << 1) / r + s >= ans) return;
	
	register int nowh;
	for (rint i = r - 1; i >= left; i --)
	{
		if (left == m) s = i * i;
		nowh = min ((n - v - b[left-1])/(i*i), h - 1);
		for (rint j = nowh; j >= left; j --)
		{
			niconi (v + i*i*j, s + ((i*j)<<1), left - 1, i, j);
		}
	}
}

int main ()
{
	cin >> n >> m;
	niconi (0, 0, m, n+1, n+1);
	if (ans == 0x3f3f3f3f) cout << "0" << kiana;
	else cout << ans << kiana;
	return 0;
}
