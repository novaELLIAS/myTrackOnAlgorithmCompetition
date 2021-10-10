#pragma GCC optimize ("Ofast")

#include <stdio.h>
#include <queue>
//#include <ext/pb_ds/priority_queue.hpp>

#define ll unsigned long long
#define rint register int

using namespace std;

//using namespace __gnu_pbds;
/*
inline ll read () {
	ll x=0ll,t=1ll;
	char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=(x<<1)+ch-48,ch=getchar();
	return x*t;
}
inline int rread () {
	int x=0ll,t=1ll;
	char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=(x<<1)+ch-48,ch=getchar();
	return x*t;
}
*/
int _, n, m;
ll in;
bool flag;

/*__gnu_pbds::*/priority_queue <ll/*, greater <ll>, pairing_heap_tag*/> aa;
/*__gnu_pbds::*/priority_queue <ll/*, greater <ll>, pairing_heap_tag*/> bb;
/*__gnu_pbds::*/priority_queue <ll/*, greater <ll>, pairing_heap_tag*/> ct;

inline bool IsPrime (int mm) {
	for (long long i = 2; i < mm/2; i ++) if (mm % i == 0) return false;
	return true;
}

int main () {
	scanf ("%d", &_);
	while (_ --) {
		//a = 1ll;
		flag = false;
		while (!aa.empty ()) aa.pop ();
		while (!bb.empty ()) bb.pop ();
		while (!ct.empty ()) ct.pop ();
		//n = rread (), m = rread ();
		scanf ("%d %d", &n, &m);
		for (rint i = 1; i <= n; i ++) scanf ("%lld", &in), aa.push (in);
		for (rint i = 1; i <= m; i ++) scanf ("%lld", &in), bb.push (in);
		int i = 1;
		//for (register int i = 1; i <= m;) {

		while (!flag && i <= m && bb.top () == aa.top ()) {
			aa.pop ();
			bb.pop ();
			i ++;
			while (!flag && i <= m && aa.top () != bb.top ()) {
				if (aa.top () != 1) {
					ct.push (aa.top ());
					if (ct.size ()> 1) puts ("NO"), flag = true;
				}
				aa.pop ();
			}
		}
		//puts ("nico1");
		while (!flag && !aa.empty ()) {
			if (aa.top () != 1) {
				ct.push (aa.top ());
				if (ct.size ()> 1) puts ("NO"), flag = true;
			}
			aa.pop ();
		}
		//puts ("nico3");
		//}

		//cout << a << endl;
		//while (!ct.empty ())
		//{
		if (!flag) {
			while (ct.top () == 1) ct.pop ();
			ct.pop ();
			if (!ct.empty ()) puts ("NO");
			else puts ("YES");
		}

		//}

		/*
				if (IsPrime (a)) puts ("YES");
				else puts ("NO");
		*/
	}
	return 0;
}
