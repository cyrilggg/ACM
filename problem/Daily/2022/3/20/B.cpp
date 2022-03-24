#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 210;
int a[N];
int n, k;

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i ++ )  cin >> a[i];
    sort(a + 1, a + 1 + k);
    a[0] = 0, a[k + 1] = n + 1;
    int ans = 0;
    for (int i = 1; i <= k + 1; i ++ )
    {
        ans = max(ans, a[i] - (a[i - 1] + ans));
    }
    cout << ans << endl;
}

signed main()
{
   int t = 1;
   cin >> t;
   while (t -- )solve();
}