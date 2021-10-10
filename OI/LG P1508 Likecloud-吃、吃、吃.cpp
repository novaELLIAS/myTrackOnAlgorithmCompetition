#include <stdio.h>
#include <ctype.h>

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

using namespace fastIO;
int dat[202][2];
#define rint register int
inline const int& max (const int&x, const int& y) {return x>y? x:y;}

int main ()
{
	register int n, m, k = 0, t = 1; cin >> n >> m;
	dat[0][0] = dat[0][1] = dat[m+1][0] = dat[m+1][1] = -233333333;
	for (rint i = 1; i <= n; i ++, k ^= 1, t ^= 1) {
		for (rint j = 1; j <= m; j ++)
		{
			cin >> dat[j][k];
			dat[j][k] += max (dat[j-1][t], max (dat[j][t], dat[j+1][t]));
		}
	}
	cout << max (dat[m>>1][t], max (dat[(m>>1)+1][t], dat[(m>>1)+2][t]));
	return 0;
}
