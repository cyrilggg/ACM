#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 25;
int n, sum;
int a[N];

bool check(int x)
{
    int cnt = 0;
    for (int i = 1; i <= n; i ++ )
    {
        cnt += a[i];
        if (cnt == x)
        {
            cout << cnt << ' ' << x <<' '<< sum - cnt << endl;
            return sum - cnt >= x;
        }
    }
    return false;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ )  cin >> a[i], sum += a[i];
    sort(a + 1, a + 1 + n);
    int l = 0, r = 1e9;
    while (l < r)
    {
        int mid = l + r >> 1;
        cout << l << ' ' << r << endl;
        if (!check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l - 1 << endl;
}

signed main()
{
   int t = 1;
   //cin >> t;
   while (t -- )solve();
}