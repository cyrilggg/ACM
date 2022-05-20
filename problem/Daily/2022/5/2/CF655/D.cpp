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
    vector<pair<int, int>>v(n);
    
    for (int i = 0; i < n; i ++ )
    {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    map<int,int>mp;
    int need = n - 1 >> 1;
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i ++ ){
        if (mp.count(v[i].second - 1) || mp.count(v[i].second + 1) || cnt == need){
            ans += v[i].first;
        }
        else{
            if (cnt < need){
                mp[v[i].second] = 1;
                //cout << v[i].second << endl;
                cnt ++;
            }
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