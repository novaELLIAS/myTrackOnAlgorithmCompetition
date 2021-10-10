//在本题中，我们直接使用c数组进行累加，所以没有开a数组
//<&x>为跳转符，与其后注释无关
//以下是C++代码

#include<cstdio>

int n, c[40000] = {0}, ans[16000] = {0};   //n:星星的个数;c数组:用于构造树状数组;ans数组:用于累加;

//这三个函数的证明在注释[1]中
inline int lowbit(const int &x);                      //lowbit:用于计算x^2
inline void doing_c(int x);                           //doing_c:用于更新树状数组
inline int getsum(int x);                             //getsum:用于求和

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		++x;                                           //树状数组从c[1]开始处理，因为x=0时，<&x>处的while循环会出现死循环
		++ans[getsum(x)];
		doing_c(x);
	}
	for(int i = 0; i < n ; ++i) {
		printf("%d\n", ans[i]);
	}
}

inline int lowbit(const int &x)
{
	return x & (-x);
}

inline void doing_c(int x)
{
	while (x <= 32001) {                                //<&x>单组输入处理时，x的最大值未知，按照题目限制循环
		++c[x];
		x += lowbit(x);
	}
}

inline int getsum(int x)
{
	int s(0);
	while(x > 0) {
		s += c[x];
		x -= lowbit(x);
	}
	return s;
}
