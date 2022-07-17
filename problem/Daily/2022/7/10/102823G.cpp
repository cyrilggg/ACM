#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
constexpr int maxn = 1e5 + 5;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t(0);
    cin >> t;
    for (int _(1); _ <= t; ++_)
    {
        int n;
        cin >> n;
        set<i64> a;
        vector<i64> na;
        for (int i(0); i < n; ++i)
        {
            int tmp;
            cin >> tmp;
            a.insert(tmp);
        }
        for (auto e : a)
        {
            na.emplace_back(e);
        }
        if (na.size() == 1)
        {
            if (na[0] == 1)
                cout << "Case " << _ << ": 1\n";
            else
                cout << "Case " << _ << ": 0\n";
        }
        else
        {
            i64 k = na[1] - na[0];
            for (int i(1); i < na.size(); ++i)
                k = __gcd(k, na[i] - na[i - 1]);

            if (k == 1)
                cout << "Case " << _ << ": -1\n";
            else if (__gcd(k, na[0]) > 1) cout << "Case " << _ << ": 0\n";
            else
            {
                for (int i = 2; i <= 1e5; i ++ )
                {
                    if ((k % i) == 0)
                    {
                        k = i;
                        break;
                    }
                }
                cout << "Case " << _ << ": " << k - na[0] % k << "\n";
            }
        }
    }
}