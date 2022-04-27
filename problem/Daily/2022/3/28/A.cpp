#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    string a;
    cin >> n >> a;
    vector<int>zero, one;
    for (int i = 0; i < n; i ++ )
        if (a[i] == '0')zero.push_back(i);
        else one.push_back(i);
    int idx = 0;
    int cnt = 0, res = 0;
    for (int i = 0; i < zero.size(); i ++ )
    {
        cnt = 0;
        while(idx < one.size() && one[idx] < zero[i]) idx ++;
        if (i < zero.size() - 1)
        {
        while (idx < one.size() && i < zero.size() - 1 && one[idx] < zero[i + 1])
        {
            cnt ++;
            idx ++;
        }
        res += max(2 - cnt, 1ll * 0);
        }
    }
    cout << res << endl;
}

signed main()
{
    int t;
    cin >> t;
    while (t -- )solve();
    return 0;
}