#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string>v(n);
    for (int i = 0; i < n; i ++ )
        cin >> v[i];
    for (int i = 0; i < m; i ++ )
    {
        int last = n - 1;
        for (int j = n - 1; j >= 0; j --)
        {
            //cout << j << endl;
            if (v[j][i] == '.' && v[last][i] != '.')last = j;
            while (j >= 0 && v[j][i] == '.') j --;
            if (j >= 0 && last >= 0 && v[last][i] == '.' &&v[j][i] == '*')
            {
                swap(v[j][i], v[last][i]);
                last --;
                
            }
            if (j >= 0 && v[j][i] == 'o')
            {
                last = j - 1;
            }
        }
    }
    for (int i = 0; i < n; i ++ )
        cout << v[i] << endl;
}

signed main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int _ = 1;
   cin >> _;
   while (_--)
      solve();
}