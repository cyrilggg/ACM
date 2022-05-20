#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))
int f[5010], sum[5010];
void solve()
{
    int n;
    cin >> n;
    vector<int>v(n + 1);
    memset(f, 0, sizeof f);
    for (int i = 1 ; i <= n; i ++ ) 
        cin >> v[i];

    int ans = 0;
    
    for (int i = 1; i <= n; i ++ )
        for (int j = i + 1; j <= n; j ++ )
            if (v[i] > v[j]) f[i] ++;    
    
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j < i; j ++ )
            if (v[j] > v[i]) f[j] --;// 使得f[j]不存比他小的C
        
        for (int j = 1; j < i; j ++ )
        {
            sum[j] = sum[j - 1] + f[j];
        }   
        
        for (int j = 1; j < i; j ++ )
        {
            if (v[j] < v[i])ans += sum[i - 1] - sum[j];
        }
    }
    cout << ans << endl;
}
 
signed main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int _ = 1;
   cin >> _;
   while (_--)
      solve();
}