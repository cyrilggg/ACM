#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
vector<pair<int,int>>v;

int n, k;
bool check(double x)
{
    vector<double>a(n);
    for (int i = 0; i < n; i ++ )
        a[i] = v[i].first - x * v[i].second;
    sort(a.begin(), a.end());
    double sum = 0;
    for (int i = n - 1; i>= n - k; i -- )
        sum += a[i];
    return sum >= 0;
}
void solve()
{
   cin >> n >> k;
    for (int i = 1; i <= n; i ++ )
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    double l = 0, r = 100000;
    for (int i = 0; i < 100; i ++ )
    {
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << setprecision(7) << l << endl;
}

signed main()
{
   int _ = 1;
   cin >> _;
   while ( _-- )solve();
}