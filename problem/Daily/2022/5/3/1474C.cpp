#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))
int n;
bool mp[2005];
int v[2005];

bool check(int x)
{
    memset(mp, 0, sizeof mp);
    mp[x] = 1;
    mp[2 * n - 1] = 1;
    vector<pair<int, int>> p;
    p.push_back({v[x], v[2 * n - 1]});
    int last = v[2 * n - 1];
    int r = 2 * n - 1;
    for (int i = 1; i < n; i++)
    {
        while (mp[r])
            r--;
        int l = 0;
        while (mp[l] || (v[l] + v[r] != last))
        {
            ++ l;
            if (l >= r)
            {
                break;
            }
        }
        if (l >= r)
        {
            break;
        }
        mp[l] = 1;
        mp[r] = 1;
        p.push_back({v[l], v[r]});
        last = v[r];
     //   cout << l << ' ' << r << endl;
    }
    
    if (p.size() == n)
    {
        cout << "YES" << endl;
        cout << v[x] + v[2 * n - 1] << endl;
        for (auto &pp : p)
        {
            cout << pp.first << ' ' << pp.second << endl;
        }
        return true;
    }
    return false;
}

void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++)
        scanf("%d",&v[i]);
    
    sort(v, v + 2 * n);
    for (int i = 0; i < 2 * n - 1; i++)
    {
        if (check(i))
            return;
    }
    cout << "NO" << endl;
    return;
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int _ = 1;
    scanf("%d",&_);
    while (_--)
        solve();
}
