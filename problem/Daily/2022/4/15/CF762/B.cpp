#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e9 + 10;
vector<int>v;
void solve()
{
    int x;
    cin >> x;
    cout << upper_bound(v.begin(), v.end(), x) - v.begin() << endl;
}

signed main()
{
    for (int i = 1; i * i <= N; i ++ )
        v.push_back(i * i);
    for (int i = 1; i * i * i <= N; i ++ )
        v.push_back(i * i * i);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int _ = 1;
    cin >> _;
    while (_--)
      solve();
}