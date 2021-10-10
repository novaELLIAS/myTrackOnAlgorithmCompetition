#include <stdio.h>
#include <string.h> 

#define max(x,y) x>y? x:y
#define min(x,y) x<y? x:y

inline int fastread();
inline void fastwrite(int);
inline void fastwriteline(int);

#define maxn 11000010

char in[maxn], str[maxn * 2];
int pos, mr;
int nico[maxn*2];

int INIT()
{
	int tlen = strlen(in);
	str[0] = '@';
	str[1] = '#';
	int pt = 2;
	for (int i = 0; i <= tlen; i ++)
	{
		str[pt ++] = in[i];
		str[pt ++] = '#';
		str[pt] = '$';
	}
	return pt;
}
int main()
{
	scanf("%s", in);
	int len = INIT();
	int ans = -2333;
	for (int i = 1; i < len; i ++)
	{
		if (i < mr)
		{
			nico[i] = min(nico[2*pos-i], mr-i); 
		} else nico[i] = 1;
		while (str[i - nico[i]] == str[i + nico[i]])
		{
			nico[i] ++;
			
		}
		if (mr < i+nico[i])
		{
			pos = i;
            mr = i + nico[i];
		}
		ans = max (ans, nico[i]-1);
	}
	
	fastwrite(ans);
	return 0;
}

inline int fastread()
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
inline void fastwrite(int x)
{
	if(x < 0) x = -x, putchar('-');
	if(x > 9) fastwrite(x / 10);
	putchar(x%10 + '0');
}
inline void fastwriteline(int x)
{
	fastwrite(x);
	putchar('\n');
}
