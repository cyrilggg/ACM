/*
    Rating : 1300
    Ҫ��һ������ֻ����������������һ����1����������Ŀ��������Ҫ��֤����Ҳ���������ɣ�Ҫע���������Ҫ�ģ�I64ʱҪ��64λ�ģ���Ȼ�ᱻ��TLE
    #define int long long Ҳ����
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