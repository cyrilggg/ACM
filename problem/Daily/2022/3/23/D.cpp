#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define int long long
const int N = 3e5 + 10;
int f[N];

void solve()
{
    memset(f, 0, sizeof f);
    int n, C;
    cin >> n >> C;
    for (int i = 1; i <= n; i ++ )
    {
        int c, d, h;
        cin >> c >> d >> h;
        f[c] = max(f[c], d * h);
    }
    for (int i = 1; i <= C; i ++ )
        for (int j = 2 * i; j <= C; j += i)
            f[j] = max(f[j], f[i] * j / i);
    
    for (int i = 1; i <= C; i ++ )
        f[i] = max(f[i - 1], f[i]);

    int q;
    cin >> q;
    while (q -- )
    {
        int x, y;
        cin >> x >> y;
        if (x * y > f[C])
            cout << -1 << ' ';
        else
            cout << upper_bound(f + 1, f + 1 + C, x * y) - f << ' ';
    }
    cout << '\n';
}

signed main()
{
    int t;
    cin >> t;
    while (t -- )solve();
    return 0;
}