#prag\
ma G++ optimize ("Ofast", 3)
#prag\
ma GCC optimize ("Ofast", 3)
#prag\
ma GCC target ("sse3","sse2","sse")
#prag\
ma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#prag\
ma GCC target ("f16c")
#prag\
ma G++ target ("sse3","sse2","sse")
#prag\
ma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#prag\
ma G++ target ("f16c")

#include <cstdio>
#include <cstring>
#include <cctype>
#include <queue>
#include <cstdlib>

using namespace std;

#define gc() getchar ()

inline int read ()
{
	register int x = 0;
	register char c = gc();
	while (!isdigit(c)) c = gc();
	while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
	return x;
}

#define rint register int
#define maxn 55

pair <int, int> nxt[maxn][maxn][4];
char dat[maxn][maxn], s[10015];
int vis[maxn][maxn];
struct node {
	int x, y, ste, sum;
};
queue <node> que;

int main ()
{
	register int n, m;
	register pair <int, int> zero = make_pair (0, 0);
	while (scanf ("%d %d", &n, &m) != EOF)
	{
		fill (vis[0], vis[0] + maxn*maxn, -1);
		fill (nxt[0][0], nxt[0][0] + maxn*maxn*4, zero);
		for (rint i = 1; i <= n; i ++) scanf ("%s", dat[i] + 1);
		scanf ("%s", s + 1);
		register int lens = 1;
		while (s[lens]) ++ lens;
		s[lens] = '*';
		
		register char ch;
		for (rint i = 1; i <= n; i ++)
		{
			for (rint j = 1; j <= m; j ++)
			{
				ch = dat[i][j];

				if (dat[i-1][j] != ch) nxt[i][j][0] = make_pair (i-1, j);
				else nxt[i][j][0] = nxt[i-1][j][0];

				for (rint k = i + 1; k <= n; k ++)
				{
					if (dat[k][j] != ch) {nxt[i][j][1] = make_pair (k, j); break;}
				}

				if (dat[i][j-1] != ch) nxt[i][j][2] = make_pair (i, j-1);
				else nxt[i][j][2] = nxt[i][j-1][2];

				for (rint k = j + 1; k <= m; k ++)
				{
					if (dat[i][k] != ch) {nxt[i][j][3] = make_pair (i, k); break;}
				}
			}
		}

		while (!que.empty()) que.pop();
		que.push ((node) {1, 1, 0, 0});
		register node fr;
		register int nowx, nowy, nste, nsum, gox, goy;
		while (!que.empty())
		{
			fr = que.front(), que.pop ();
			nowx = fr.x, nowy = fr.y, nste = fr.ste, nsum = fr.sum;
			if (dat[nowx][nowy] == s[nste + 1])
			{
				que.push ((node) {nowx, nowy, nste + 1, nsum + 1});
				if (nste + 1 == lens) {printf ("%d\n", nsum + 1); break;}
			}
			else
			{
				for (rint i = 0; i <= 3; i ++)
				{
					gox = nxt[nowx][nowy][i].first, goy = nxt[nowx][nowy][i].second;
					if(!gox || !goy) continue;
					if (vis[gox][goy] < nste) { vis[gox][goy] = nste; que.push ((node){gox, goy, nste, nsum + 1});}
				}
			}
		}
	}

	return 0;
}
