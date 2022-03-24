#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int ans;
bool st[N];

int gcd(int a,int b)
{
    if(b == 0)
        return a;
    else return gcd(1ll * b,1ll * a % (1ll * b));
}

void solve()
{
    int l, r;
    cin >> l >> r;

    for (int i = r; i >= 1; i -- )
    {
        if (r / (1ll * i) > 0)
        {
            int cur = 1ll * r / (1ll * i) * i;
            vector<int>tmp;
            while (cur >= l)
            {
                if (st[cur])
                {
                    cur -= i;
                    continue;
                }
                tmp.push_back(cur);
                cur -= i;
            }
            if (tmp.size() > 1)
            {
                reverse(tmp.begin(), tmp.end());
                for (int j = 1; j < tmp.size(); j ++ )
                {
                    //cout << "===" << endl;
                    //cout << i <<' '<< tmp[0] << ' ' << tmp[j] << endl;
                    st[tmp[j]] = 1;
                    ans += 1ll * tmp[0] * tmp[j] /(1ll *  gcd(tmp[0], tmp[j]));
                    //cout << ans << endl;
                    cout << tmp[0] << ' ' << tmp[j] <<' '<< 1ll * tmp[0] * tmp[j] /(1ll *  gcd(tmp[0], tmp[j])) << endl;
                    //printf("tmp[0] = %lld, tmp[%lld] = %lld, i = %lld\n",tmp[0], j, tmp[j], i);
                }
            }

        }
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