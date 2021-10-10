

10 1
A 2 3 5


int - %d
float - %f
double - %lf
char - %c
char[] - %s

int x;
do {
	x=RANDOM() || (RANDOM() << 1) || (RANDOM() << 2)
} while(x > 4);
return x;


int n; // 网格大小为n*n
int XY[MAXN]; // 全局数组XY储存当前的方案，XY[2]=3表示有一个皇后在(2,3)位置
// ...
bool search(int x) // 搜索第x行放哪个位置，如果有一种方案则返回true否则返回false
{
	if (x == n+1) return true; // 找到方案
	for(int y = 1; y <= n; y ++)
		if (/*(x,y)这个位置可以放*/)
		{
			/* 将皇后放在(x,y)上 */
			XY[x] = y;
			if (search(x+1)) return true;
			/* 取消(x,y)上的皇后 */
		}
	return false;
}

int n; // 网格大小为n*n
int XY[MAXN]; // 全局数组XY储存当前的方案，XY[2]=3表示有一个皇后在(2,3)位置
bool column[MAXN]; // 列
bool skew1[MAXN*2]; // 右上到左下
bool skew2[MAXN*2]; // 左上到右下
bool search(int x) // 搜索第x行放哪个位置，如果有一种方案则返回true否则返回false
{
	if (x == n+1) return true; // 找到方案
	for(int y = 1; y <= n; y ++)
		if (!column[y] && !skew1[x+y] && !skew2[x-y+n])
		{
			/* 将皇后放在(x,y)上 */
			column[y] = true;
			skew1[x+y] = true;
			skew2[x-y+n] = true;
			
			XY[x] = y;
			if (search(x+1)) return true;
			
			/* 取消(x,y)上的皇后 */
			column[y] = false;
			skew1[x+y] = false;
			skew2[x-y+n] = false;
		}
	return false;
}










char* s = "123\0sadwwew324";

strlen()


int que[10];
int start, tail;

tail=15;
que[tail%10]=x;


>>> 3^4 // 011 ^ 100 = 111 = 7
7
>>> 1^2 // 01 ^ 10 = 11 = 3
3
>>> 4^6 // 100 ^ 110 = 10 = 2
2







char cque[];
int len=0;
void put(int x)
{
	if(x==0)return;
	put(x/10);
	cque[++len]=x%10+'0';
}


// 逆元可以把除法变成乘法（求余意义下）

费马小定理：p是素数并且gcd(a,p)=1 => a^(p-1) % p = 1
=> a的逆元为a^(p-2) % p


