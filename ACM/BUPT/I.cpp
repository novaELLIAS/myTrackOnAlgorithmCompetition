#include <cstdio>
#include <string>
#include <iostream>
#include <ctype.h>

using namespace std;

signed main () {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	string s;
	register int a, b, len;
	while (n --) {
		cin >> s;
		if (!(s[0] ^ '-')) printf("0\n");
		else {
			len = s.length(); a = b = 0;
			for (register int i=0; s[i]^'\0'; ++ i) {
				if (isdigit(s[i])) b = (b<<3)+(b<<1)+s[i]-'0';
				if (s[i] == '+') a ^= b ^= a ^= b;
			} printf("%d\n", a + b * 20);
		}
	}
}
