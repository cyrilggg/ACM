/*
    Rating : 2000
    出题人的锅，根本没考虑并列最小的情况，害的卡了很久。
    很容易分析出c为长度肯定比大于c的长度最少，因此完全可以状态机dp推过来，另外用RMQ预处理一下区间最小值就可以了
    dp[i]表示 i为结尾的序列
    dp[i] = dp[i - 1] + a[i] 直接从后往前加
    dp[i] = dp[i - c] + s[i - c, i] + min[i - c,i]表示的是用区间包装时候的最小
    都取一个min就过了，就是要考虑并列最小白卡一小时
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define int long long
const int N = 1e5 + 10, M = 18;
int a[N];
int dp[N];
int s[N];
int n, c;
int f[N][M];
int lg[N];
void _init_() 
{
    for (int i = 2; i <= N  ; ++i) {
        lg[i] = lg[i / 2] + 1; // 以2为底i的对数 
    }
}
void init()
{
    for(int j=0;j<M;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            if(!j)f[i][j]=a[i];
            else f[i][j] = min(f[i][j-1],f[i+(1<<j-1)][j-1]);
        }
}

int query(int l,int r)
{
    int len=r-l+1;
    int k = lg[len];
    return min(f[l][k],f[r-(1<<k)+1][k]);
}

signed main()
{
    cin >> n >> c;
    for (int i = 1; i <= n; i ++ )  
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    _init_();
    init();

    memset(dp, 0x3f, sizeof dp);

        dp[0] = 0;
        for (int i = 1; i <= n ; i ++ )
        {
            if (i < c) dp[i] = dp[i - 1] + a[i];
            else
            {
                dp[i] = min(dp[i], min(dp[i - 1] + a[i], dp[i - c] + s[i] - s[i - c] - query(i - c + 1, i)));
            }
        }
    
    cout << dp[n] << endl;
    return 0;
}