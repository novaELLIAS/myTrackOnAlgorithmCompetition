#include <stdio.h>
#include <string.h>

#define maxn 100001
#define dmax 200010
#define rint register int

char a[dmax];

int main ()
{
	freopen ("beads.in","r",stdin);
	freopen ("beads.out","w",stdout);
	
	scanf ("%s", a);
	register int len = strlen (a) - 1;
	register bool flag = true;
	for (rint i = 0; i <= len; i ++) {
		if (a[i] == '2') flag = false;
		a[len+i+1] = a[i];
	}
	if (flag) {puts ("TvT"); return 0;}
	len = (len << 1) + 1;
	register int cnt = 0, ans = 0, i = 0;
	while (i <= len)
	{
		if (a[i] == '2') {
			i ++;
			while (a[i] == '3') i ++, cnt ++;
			ans = cnt>ans? cnt:ans; cnt = 0;
		} else i ++;
	}
	putchar ('2');
	while (ans --) putchar ('3');
	return 0;
}
