#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    vector<int>A(n), B(n);
    for (int i = 0; i < n; i ++ )   cin >> A[i];
    for (int i = 0; i < n; i ++ )   cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int diff;
    bool findd = false;
    // for (int i = 0; i < n; i ++ )   cout << A[i] << " \n"[i == n - 1];
    // for (int i = 0; i < n; i ++ )   cout << B[i] << " \n"[i == n - 1];
    for (int i = 0; i < n; i ++ )
    {
        if (A[i] == B[i])
        {
            continue;
        }
        if (A[i] - B[i] != diff)
        {
            if (findd) return void(puts("NO"));
            diff = A[i] - B[i];
            if (diff > 0 || diff < -1)return void(puts("NO"));
        }
    }
    return void(puts("YES"));
}

signed main()
{
   int _ = 1;
   cin >> _;
   while (_--)
      solve();
}