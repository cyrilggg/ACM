#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))
const int N = 1010;
char mp[N][N];
bool vis[N];
int n, m;
char che[11][11] = {
    "##########",
    "##########",
    "##########",
    "####..####",
    "###....###",
    "###....###",
    "####..####",
    "##########",
    "##########",
    "##########",
};

bool check(int x, int y)
{
    int idx = 0, idy = 0;

    for (int i = x; i < x + 10; i ++ )
    {
        idy = 0;
        for (int j = y; j < y + 10; j ++ )
        {
            if (i > n || j > m) return 0;
            if (che[idx][idy] != mp[i][j]) return 0;
            idy ++;
        }
        idx ++;
    }
    return 1;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            cin >> mp[i][j];

    vector<pair<int,int>>v;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
        {
            if (check(i, j))
            {
                v.push_back({i, j});
            }
        }
    int a = v.size();
    int b = 0;
    for (int i = 0; i < v.size(); i ++ )
    {
        if (vis[i]) continue;
        for (int j = 0; j < v.size(); j ++ )
        {
            if (vis[j]) continue;
            if (i == j) continue;
            if (v[j].first == v[i].first && v[i].second == v[j].second + 7 )
            {
                vis[i] = 1;
                vis[j] = 1;
                a -= 2;
                b ++;
            } // j 在 i 上面
            if (v[j].first == v[i].first && v[i].second == v[j].second - 7 )
            {
                vis[i] = 1;
                vis[j] = 1;
                a -= 2;
                b ++;
            } // j 在 i 下面
            if (v[j].first == v[i].first - 7  && v[i].second == v[j].second)
            {
                vis[i] = 1;
                vis[j] = 1;
                a -= 2;
                b ++;
            } // j 在 i 下面
            if (v[j].first == v[i].first + 7 && v[i].second == v[j].second)
            {
                vis[i] = 1;
                vis[j] = 1;
                a -= 2;
                b ++;
            } // j 在 i 下面
        }
    }
    cout << b <<' '<< a << endl;
}

signed main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int _ = 1;
   //cin >> _;
   while (_--)
      solve();
}