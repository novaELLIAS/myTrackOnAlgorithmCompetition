#include <bits/stdc++.h>
using namespace std;
int dp[11][11];
#define rint register int
int main ()
{
    for (rint i = 0; i <= 10; i ++)
    {
        for (rint j = 0; j <= 10; j ++)
        {
            if (i == 0 || j == 1) dp[i][j] = 1;
            else if (j > i) dp[i][j] = dp[i][i];
            else dp[i][j] = dp[i-j][j] + dp[i][j-1];
        }
    }
    for (rint i = 0; i <= 10; i ++)
    {
        putchar ('{');
        for (rint j = 0; j <= 10; j ++)
        {
            printf ("%d, ", dp[i][j]);
        }
        putchar ('}');
        putchar ('\n');
    }
    return 0;
}
