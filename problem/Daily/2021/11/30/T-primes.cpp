/*
    Rating : 1300
    要找一个因子只有三个的数，因子一定是1，本身和他的开方，因此要保证开方也是素数即可，要注意的是输入要改，I64时要用64位的，不然会被卡TLE
    #define int long long 也不行
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;


signed main()
{
    int t;
    scanf("%d", &t);
    while (t -- )
    {
        long long n;
        scanf("%I64d",&n);
        bool flag = true;        
        long long m = sqrt(n);
        for (int i = 2; i <= m / i; i ++ )
        {
            if( m % i == 0 )
            {
                flag = false;
                break;
            }
        }
        if (m * m == n && flag && n > 3)puts("YES");
        else puts("NO");
    }
    return 0;
}