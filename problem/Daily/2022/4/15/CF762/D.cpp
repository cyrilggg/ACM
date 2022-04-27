#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>>p;
    p.assign(n, vector<int>(m));
    for (int i = 0; i < m; i ++ )
        for (int j = 0; j < n; j ++ )
            cin >> p[j][i];
    
    int l = 0, r = 1e9;
    for (int i = 0; i < n; i ++ )
        r = min(r, (*max_element(p[i].begin(), p[i].end())));
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        vector<bool>v(m);
        bool nice = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (p[i][j] >= mid) {
                    if (v[j]) {
                        nice = true;
                    }
                    v[j] = true;
                }
            }
        }
        if (nice) {
            l = mid; 
        } else {
            r = mid - 1;
        }
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