#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
vector<int>edges[100010], dp(1000010, 1e12);
signed main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>>v(m + 1);
    for (int i = 1; i <= m; i ++ )
    {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        edges[y].push_back(x);
    }

    for (int i = 1; i <= m; i ++ )
    {
        sort(edges[i].begin(), edges[i].end());
    }

    deque<int>q;
    q.push_back(0);
    dp[0] = 0;
    for (int i = 1; i <= n; i ++ )
    {
        for (auto l : edges[i])
        {
            while (q.front() < l - 1) q.pop_front();
            dp[i] = min(dp[i], dp[l - 1]);
            dp[i] = min(dp[q.front()] + q.front() - l + 1, dp[i]);
        }
        while (q.size() && dp[q.back()] + q.back() >= dp[i] + i) q.pop_back();
        q.push_back(i);
    }

    if (dp[n] == 1e12) cout << -1 << endl;
    else cout << dp[n] << endl;
    return 0;
}