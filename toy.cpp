#pragma G++ optimize ("Ofast", 3)

#include <cstdio>
#include <queue>
#include <set>

using namespace std;

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline long long read ()
{
	register long long x = 0; register char c = gc(); register bool m = 0;
	while ((c < '0' || c > '9') && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
static void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (int x) {write (x); putchar ('\n');}

typedef long long ll;
#define Re register
#define maxn 300001

long long dat[maxn], sum[maxn], dp[maxn];

multiset <long long> sjb;
deque <int> que;

int main ()
{
	freopen ("toy.in", "r", stdin);
	freopen ("toy.out","w",stdout);
	
	register int n = (int) read (), elf = 1;
	register long long LIM = read (), tmp;
	for (Re int i = 1; i <= n; ++ i) dat[i] = read (), sum[i] = dat[i] + sum[i-1];
	
	dp[1] = dat[1], sjb.insert(dp[1]), que.push_back(1);
	for (Re int i = 2; i <= n; ++ i)
	{
		//puts ("check1");
		while (sum[i] - sum[elf-1] > LIM && elf < i)
		{
			sjb.erase(sjb.lower_bound(dat[que.front()] + dp[elf-1]));
			if (que.front()^elf) sjb.insert(dat[que.front()] + dp[elf ++]);
			else if (que.front() == elf) ++ elf, que.pop_front();
		}
		//puts ("check2");
		while (que.size()>=1 && dat[i] >= dat[que.back()])
		{
			if (que.size()==1) sjb.erase(sjb.lower_bound(dat[que.back()] + dp[elf-1])), que.pop_back();
			else {
				tmp = dat[que.back()], que.pop_back(), tmp += dp[que.back()];
				sjb.erase(sjb.lower_bound(tmp));
			}
		}
		//puts ("check3");
		
		if(que.empty()) sjb.insert(dat[i] + dp[elf-1]);
		else sjb.insert(dat[i] + dp[que.back()]);
		//puts ("niconi");
		que.push_back(i), dp[i] = *sjb.begin();
		
		//puts ("check4");
	}
	
	printf ("%I64d", dp[n]);
	
	fclose (stdin), fclose (stdout);
	return 0;
}
