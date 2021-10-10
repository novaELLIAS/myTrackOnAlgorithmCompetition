#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")

#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxstar = 15000 +10;
const int maxn = 32000 + 10;
int level[maxstar], nico[maxn];
int n;
pair <int, int> a[maxstar];

#define lowbit(x) x&-x

inline void update(int pos, int num)
{
	while(pos <= 32001) {
		nico[pos] += num;
		pos += lowbit(pos);
	}
}
inline int query(int pos)
{
	int ret = 0;
	while(pos) {
		ret += nico[pos];
		pos -= lowbit(pos);
	}
	return ret;
}
int main(void)
{
	scanf("%d", &n);
	register int x, y;
	for(register int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		a[i] = make_pair (++x, ++y);
	}
	std::sort (a, a + n);
	for(register int i = 0; i < n; i++) {
		++ level[query(a[i].second)], update (a[i].second, 1);
	}
	for(register int i = 0; i < n; i++) {
		printf("%d\n", level[i]);
	}
}
