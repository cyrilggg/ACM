#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
string a[N];
int r, c;
int ans;
void solve()
{
    cin >> r >> c;
    getchar();
    for (int i = 1; i <= r; i++)
    {
        getline(cin, a[i]);
        a[i] = 'x' + a[i];
    }
    int cur = r - 3;
    while (true)
    {
        bool flag = false;
        int cury = 1;

        while (cur >= 1 && cury >= 1 && cury <= c && a[cur][cury] != '+')
        {
            cur -= 2;
            cury += 2;
        }

        if (cur >= 1 && cury >= 1 && cury <= c && a[cur][cury] == '+')
            flag = true;

        if (!flag)
            break;
        int nw = 0;
        pair<int, int> now = {cur, cury};
        while (now.first >= 1 && now.second >= 1 && now.second <= c && a[now.first][now.second] == '+')
        {
            while (now.first >= 1 && now.second >= 1 && now.second + 4 <= c && a[now.first][now.second + 4] == '+')
            {
                nw++;
                now.second += 4;
            }
            cout << now.first << ' ' << now.second << ' ' << nw << endl;
            ans += nw;
            now.first -= 2;
            now.second += 2;
        }
        ans -= nw;
        cur -= 3;
    }
    cout << ans << endl;
}

signed main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}