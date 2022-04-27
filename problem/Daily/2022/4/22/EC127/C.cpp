#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int>v(n + 1);
    for (int i = 1; i <= n; i ++ )  cin >> v[i];
    int ans = 0;
    
    sort(v.begin(), v.end());
    int sum = 0;
    for (int i = 1; i <= n; i ++ ){
        //cout <<"===" << v[i] << endl;
        sum += v[i];
        if (k < sum) break;
        int x = max((k - sum) / i + 1, 0ll);
        //cout <<"==="<< x << endl;
        ans += x;
    }
    cout << ans << endl;
    // int st = 0;
    // bool flag = false;
    // for (int i = 1; i <= n; i ++ )
    // {
    //     sum[i] = sum[i - 1] + v[i];
    //     if (sum[i] > k && !flag)
    //     {
    //         st = i - 1;
    //         flag = 1;
    //     }
    // }
    // if (st == 0 && sum[n] <= k) st = n;
    // int cnt = 1;

    // while (1){
    //     if (st == 0) break;
    //     ans += st;
    //     int j = st;
    //     while (j && sum[j] + cnt * j > k){
    //         j --;
    //     }
    //     st = j;
    //     cnt ++;
    // }
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