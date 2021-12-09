/*
    Rating : 1700
    随手抽的dp竟然还是状态机dp..看来状态机dp在这个区间真的很常见，不过这个不太好写
    要先枚举距离以及要预处理dp[0][0] = dp[0][1] = 0;
    之前我是先让dp[1][0] 等于的，确实不太合适
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