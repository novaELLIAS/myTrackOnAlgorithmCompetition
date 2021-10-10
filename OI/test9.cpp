#include <bits/stdc++.h>

using namespace std;

class fastio {
	private:
		inline char gc() {
			static char buf[1<<14],*p1=buf,*p2=buf;
			return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
		}
		inline bool isdig (char c) { return c>='0'&&c<='9';}
	public:
		inline int getint () {
			register int x = 0; register char c = gc(); register bool m = false;
			while (c ^ '-' && (c<'0'||c>'9') && c ^ '-') c = gc();
			if (!(c ^ '-')) c = gc(), m = true;
			while (isdig (c)) x = (x << 3) + (x << 1) + c ^ '0', c = gc();
			return m? -x : x;
		}
		inline int getuint () {
			register int x = 0; register char c = gc();
			while (!isdig(c)) c = gc();
			while ( isdig(c)) x = (x << 3) + (x << 1) + c ^ '0', c = gc();
			return x;
		}
		inline double getdou () {
			register double x = 0; register char c = gc (); register bool m = false;
			while (!isdig(c) && c ^ '-') c = gc ();
			if (!(c ^ '-')) c = gc(), m = true;
			while (isdig(c)) x = x * 10 + (c ^ '0'), c = gc ();
			if (!(c ^ '.')) {
				register double s = 0.1; c = gc ();
				while (isdig(c)) x = x + (c ^ '0') * s, s /= 10, c = gc ();
			} return m? -x : x;
		}
		inline double getudou () {
			register double x = 0; register char c = gc ();
			while (!isdig(c)) c = gc ();
			while (isdig(c)) x = x * 10 + (c ^ '0'), c = gc ();
			if (!(c ^ '.')) {
				register double s = 0.1; c = gc ();
				while (isdig(c)) x = x + (c ^ '0') * s, s /= 10, c = gc ();
			} return x;
		}
		static void writeuint (int x)
		{
			if (x > 9) writeuint (x / 10);
			putchar (x % 10 + 48);
		}
		static void writelen (int x) {if (x<0) x = -x, putchar('-'); writeuint (x); putchar ('\n');}
} fastio;

signed main () {
	printf ("%d", (7<<3)^1); 
}
