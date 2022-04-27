#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define returnNo return void(puts("No"))
#define returnYes return void(puts("Yes"))
void solve()
{
    int n;
    cin >> n;
    vector<int>v(n);
    for (int i = 0; i < n; i ++ ){
        cin >> v[i];
    }
    int cnt = 0;
    vector<pair<int, int>>p;
    for (int i = 0; i < n - 1; i ++ )
    {
        if (v[i] == v[i + 1])
            p.push_back({i, i + 1});
    }
    if (p.size() <= 1) cout << 0 << endl;
    else cout << (p.back().first - p[0].second > 0 ? (p.back().first - p[0].second): 1)  << endl;
    // for (int i = 0; i < n - 1; i ++ ){
    //     if (v[i] == v[i + 1]){
    //         int st = i;
    //         int cnt = 1;
    //         while(i < n - 1 && v[i] == v[i + 1]){
    //             i ++;
    //             cnt ++;
    //         }
    //         length.push_back({cnt, st});
    //     }
    // }
    // int ans = 0;
    // for (int i = 0; i < length.size(); i ++ ){
    //     if (length[i].first == 3) ans += 1;
    //     else if (length[i].first > 3)ans += length[i].first - 3;
    // }
    // for(int i = 1; i < length.size(); i ++ ){
    //     if (length[i].second - (length[i - 1].first + length[i - 1].second - 1) > 1)ans += 2;
    //     else ans += 1;
    //     cout << ans << endl;
    // }
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