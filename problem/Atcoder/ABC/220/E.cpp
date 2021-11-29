#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
const int mod = 998244353;
int p[N], n, d;
signed main() {
    cin >> n >> d;
    p[0] = 1;
    for (int i = 1; i < N; ++i) p[i] = p[i - 1] * 2 % mod;
 
    int ans = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (n - i >= d)
            ans = (ans + p[d] * p[i - 1] % mod) % mod;
    
        int l = min(d - 1, n - i);
        int r = d - l;
        if (r > n - i) continue;
        ans = (ans + (l - r + 1) * p[d - 2] % mod * p[i - 1] % mod) % mod;
        cout << ans <<endl;
    }
 
    cout << ans * 2 % mod << endl;
    return 0;
}
