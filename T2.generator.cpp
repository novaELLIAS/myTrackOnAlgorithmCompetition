#pragma G++ optimize (3)
#include <bits/stdc++.h>
using namespace std;
#define Re register
#define maxn 100000
#define mod1 10000
#define mod2 10000000
typedef long long ll;
inline ll random (Re ll modn)
{
	return 1ll*rand()*rand()%modn;
}
int main ()
{
	freopen ("fight.in","w",stdout);
	register ll n = maxn; printf ("%I64d\n", n);
	while (n --) printf ("%I64d %I64d\n", random(200000000ll), random(1000000ll));
	printf ("%I64d\n", random(1000));
	fclose (stdout);
	return 0;
}
