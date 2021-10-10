#include <stdio.h>
#include <stdlib.h>

inline int fastread();
inline void fastwrite(int);
inline void fastwriteline(int);

#define max(a, b) a>b? a:b
#define min(a, b) a<b? a:b
#define ins "intersect"
#define uns "not intersect"

int t;
int x1, y1, x2, y2, x3, y3, x4, y4;

void ansfind (bool flag)
{
	if (flag == true)
	{
		puts(ins);
		exit(0);
	}
	else {
		puts(uns);
		exit(0);
	}
}
bool judge (int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4)
{
	double temp1 = (Y3 - Y1) * (X1 - X2) - (X3 - X1) * (Y1 - Y2);
	double temp2 = (Y4 - Y1) * (X1 - X2) - (X4 - X1) * (Y1 - Y2);

	if(temp1 * temp2 > 0) return false;
	else return true;
}
bool nico (int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4)
{
	if (!judge(X1, Y1, X2, Y2, X3, Y3, X4, Y4)) return false;
	if (!judge(X3, Y3, X4, Y4, X1, Y1, X2, Y2)) return false;
	
	return true;
}
int main ()
{
	t = fastread();
	while (t --)
	{
		x1 = fastread();
		y1 = fastread();
		x2 = fastread();
		y2 = fastread();
		x3 = fastread();
		y3 = fastread();
		x4 = fastread();
		y4 = fastread();
		
		if (max(y1, y2) < min(y3, y4)) ansfind(false);
		if (min(y1, y2) > max(y3, y4)) ansfind(false);
		if (max(x1, x2) < min(x3, x4)) ansfind(false);
		if (min(x1, x2) > max(x3, x4)) ansfind(false);
		
		if (nico(x1, y1, x2, y2, x3, y3, x4, y4))
		{
			puts(ins);
		}
		else puts(uns);
	}
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
