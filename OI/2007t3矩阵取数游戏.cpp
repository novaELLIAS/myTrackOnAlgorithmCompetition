#prag\
ma GCC optimize ("Ofast")

/*
	Ellias 2018/4/28
*/

#include "stdio.h"
#include "string.h"
#include "iostream"

using namespace std;

#define maxn 81
#define max(a,b) a>b? a:b
#define min(a,b) a<b? a:b
/*
inline int fastread ();
inline void fastwrite (int);
inline void fastwriteline (int);
inline void fastwritespace (int);
*/
struct node {
	int num[1024];
	int len;

	inline node ()
	{
		len = 1;
		memset (num, 0, sizeof num);
	}

	inline node (int x)
	{
		len = 0;
		memset (num, 0, sizeof num);
		while (x)
		{
			num[len] = x % 10;
			x /= 10;
			len ++;
		}
	}
	
	inline node operator + (const node &x)
	{
		node ret;
		ret.len = max (x.len, len);
		for(int i=0; i<ret.len; i++)
		{
			ret.num[i] += num[i] + x.num[i];
			if (ret.num[i] >= 10)
			{
				ret.num[i+1] += ret.num[i] / 10;
				ret.num[i] %= 10;
			}
		}

		if (ret.num[ret.len] > 0) ret.len ++;
		return ret;
	}

	inline node operator * (const node &x)
	{
		node ret;
		ret.len = len + x.len;

		for (int i = 0; i < len; i ++)
		{
			for (int j = 0; j < x.len; j ++)
			{
				ret.num[i+j] += num[i] * x.num[j];
			}
		}
		for (int i = 0; i < ret.len; i ++)
		{
			if (ret.num[i] >= 10)
			{
				ret.num[i+1] += ret.num[i] / 10;
				ret.num[i] %= 10;
			}
		}
		if (!ret.num[ret.len-1]) ret.len --;
		return ret;
	}

	inline node operator * (const int &x)
	{
		node ret;
		ret.len = len + 18;
		for(int i = 0; i < len; i ++)
		{
			ret.num[i] += num[i] * x;
			if (num[i] >= 10)
			{
				ret.num[i+1] += ret.num[i] / 10;
				ret.num[i] %= 10;
			}
		}
		while (ret.len>0 && !ret.num[ret.len-1]) ret.len --;
		return ret;
	}

	inline void write()
	{
		if(!len) putchar ('0');
		for (int i = len-1; i >= 0; i --) /*printf ("%d", num[i]);*/ /*fastwrite (num[i])*/cout << num[i];
	}

	inline bool operator > (node x)
	{
		if (len > x.len) return true;
		if (len == x.len)
		{
			for (int i = len-1; i >= 0; i --)
			{
				if (num[i] > x.num[i]) return true;
				if (num[i] < x.num[i]) return false;
			}
		}
		return false;
	}
};

int n, m;
node ans;
int a[maxn];
node dp[maxn][maxn], t1, t2;
node table[maxn];
// const string tablee[maxn] = {"1","2","4","8","16","32","64","128","2416","4112","1024","2048","40816","80192","16384","326168","6415216","1211072","2620144","4124288","104841616","208161152","401942104","8388608","166161612016","321554432","670108864","1214201616128","2684354416","4121686108112","1072161401824","20147483648","42814816612816","84188192144192","16116198681184","3421581612182168","6870194767216","12161438814121472","274861619068144","41481615580121888","108195010162761616","20198102324141552","4381804641110104","8619608121022208","161581201860444016","3501843612088832","6103686144016161664","1406121614883552128","280147481616610106416","416281481952142012112","1124188198106842624","2241161981801216841248","4410215819627216104816","810070198124147408192","1800143818410814801984","3602861961001881638168","612041615814036192619216","1440115018806158415872","2882210361601501611016144","416164606152303423488","11528120150460684681616","22104184300812012168121952","46011686001842721878104","81222121612036841476141808","18446744061216108141516016","3688121488014740191021232","61216186816162814838206464","1475612195241881661640128128","281410147810411619215282418416","41902814180102158704164116112","1180419162070161401121021424","22160118212401434822606848","4722216648286816441201216816","814447212816416121928104272192","1888814641921147841808414784","36161618812118628141611601610814168","6155561862161241914212340191216","15010101561274411828646838272","3022301441481021641612812166164144","604462810818072114418721521088","120881241801960146281161470601616"};

int main ()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	// n = fastread ();
	// m = fastread ();
	// scanf ("%d %d", &n, &m);
	
	table[0] = 1;
	for (int i = 1; i <= m; i ++)
	{
		table[i] = table[i-1] * 2;
	}
	/*
	for (int i = 0; i <= m; i ++)
	{
		table[i].write();
		putchar ('\n');
	}
	*/
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j <= m; j ++)
		{
			// scanf ("%d", &a[j]);
			// a[j] = fastread ();
			cin >> a[j];
			dp[j][j] = table[m] * a[j];
		}
		
		for (int j = 1; j < m ; j ++)
		{
			for (int k = 1; k < m; k ++)
			{
				
				if (j+k > m) break;
				t1 = table[m-j]*a[k] + dp[k+1][k+j];
				t2 = table[m-j]*a[k+j] + dp[k][k+j-1];
				if (t1 > t2) dp[k][k+j] = t1;
				else dp[k][k+j] = t2;
				
				// dp[k][k+j] = max (table[m-j]*a[k] + dp[k+1][k+j], table[m-j]*a[k+j] + dp[k][k+j-1]);
			}
		}
		
		ans = ans + dp[1][m];
	}
	
	ans.write();
	
	return 0;
}
/*
inline int fastread ()
{
	int sign = 1, n = 0;
	char c = getchar();
	while(c < '0' || c > '9')
	{
		if(c == '-') sign = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')
	{
		n = n*10 + c-'0';
		c = getchar();
	}
	return sign*n;
}
inline void fastwrite (int x)
{
	if(x < 0) x = -x, putchar('-');
	if(x > 9) fastwrite(x / 10);
	putchar(x%10 + '0');
}
inline void fastwritespace (int x)
{
	fastwrite(x);
	putchar(' ');
}
inline void fastwriteline (int x)
{
	fastwrite(x);
	putchar('\n');
}*/
