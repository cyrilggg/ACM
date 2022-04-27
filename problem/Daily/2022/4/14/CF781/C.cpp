#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 2e5 + 10;
vector<int>edges[N];
int bro[N];
int cnt;

bool check(int x)
{
    int res = 0;
    for (int i = 1, j = x - 1; i <= cnt; i ++, j -- )
    {
        res += max(0 * 1ll, bro[i] - j);
    }
    return x - cnt >= res;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ ) edges[i].clear();
    for (int i = 2; i <= n; i ++ )
    {
        int x;
        cin >> x;
        edges[x].push_back(i);
    }
    cnt = 1;
    bro[1] = 0;
    for (int i = 1; i <= n; i ++ )
    {
        if (edges[i].size())
        {
            bro[++cnt ] = edges[i].size() - 1;
        }
    }
    
    sort(bro + 1, bro + 1 + cnt, greater<int>());
    int l = cnt, r = n;
    while (l < r)  
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid ;
        else l = mid + 1;
    }
    cout << l << endl;
}

signed main()
{
   int _ = 1;
   cin >> _;
   while (_--)
      solve();
}