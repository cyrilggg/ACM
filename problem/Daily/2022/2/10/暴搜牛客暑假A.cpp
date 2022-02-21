#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
int f[N][N];
int sg(int a, int b)
{
    if (f[a][b] != -1)return f[a][b] ;
    for (int i = 1; i <= a ; i ++ )
    {
        for (int j = 0; j * i <= b; j ++ )
        {
            if(sg(a - i, b - j * i) == 0)
            {
                f[a][b] = 1;
                return 1;
            }
        }
    }
    
    for (int i = 1; i <= b ; i ++ )
    {
        int ans = 0;
        for (int j = 0; j * i <= a; j ++ )
        {
            if(sg(a - j * i, b - i) == 0)
            {
                f[a][b] = 1;
                return 1;
            }
        }
    }
    
    f[a][b] = 0;
    return 0;
}

int main()
{
    freopen("output.txt","w",stdout);
    memset(f, -1, sizeof f);
    for (int i = 1; i <= 5000; i ++ )
        for (int j = i; j <= 5000; j ++ )
        {
            if(sg(i, j) == 0)
                printf("mp[{%d, %d}] = 1\n;", i, j);
        }
    printf("FINISHED\n");
     return 0;
}