/*
    Rating : 1700
    ���ֳ��dp��Ȼ����״̬��dp..����״̬��dp�����������ĺܳ��������������̫��д
    Ҫ��ö�پ����Լ�ҪԤ����dp[0][0] = dp[0][1] = 0;
    ֮ǰ��������dp[1][0] ���ڵģ�ȷʵ��̫����
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define int long long
const int N = 1010;
int s[N];
int dp[N][2];
signed main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n ; i ++ )
    {
        for (int j = 1; j <= m; j ++ )
            {
                char x;
                cin >> x;
                if(x == '#') s[j] ++;
            }
    }
    for (int i = 1; i <= m; i ++)   s[i] += s[i - 1];
    memset (dp, 0x3f,sizeof dp);
    dp[0][0] = dp[0][1] = 0;

    for (int i = 1; i <= m; i ++ )
    {
        for (int j = x; j <= y; j ++ )
        {
            if(i - j < 0)break;
            dp[i][0] = min(dp[i - j][1] + j * n - s[i] + s[i - j], dp[i][0]);
            dp[i][1] = min(dp[i - j][0] + s[i] - s[i - j], dp[i][1]);
            //cout << i << ' ' <<j <<' '<<dp[i][0] <<  ' ' << dp[i][1] << endl;   
        }

    }
    cout << min(dp[m][1], dp[m][0]) << endl;
    return 0;
}