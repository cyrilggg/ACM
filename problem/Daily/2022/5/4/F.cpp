#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int>A(n), B(m);
    for (int i = 0; i < n; i ++ )   cin >> A[i];
    for (int j = 0; j < m; j ++ )   cin >> B[j];
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end());
    int ans = 0;
    for (int i = 0, j = 0; i < n && j < m;)
    {
        if (B[j] <= A[i])
        {
            A[i] -= B[j];
            ans ++;
            j ++;
        }
        else
        {
            i ++;
        }
    }
    cout << ans << endl;
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