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
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>heap;
    for (int i = 0;  i < n; i ++ )
    {
        cin >> v[i];
        heap.push({v[i], i});
    }
    int ans = 1e12;
    for (int i = 0; i < n - 1; i ++ )
    {
        ans = min(ans, max((max(v[i], v[i + 1]) + 1) / 2, 
                    (v[i] + v[i + 1] + 2) / 3));
        if (i)
        ans = min(ans, min(v[i - 1],v[i+1]) + (max(v[i + 1],v[i-1]) -min( v[i - 1],v[i+1])+ 1) / 2);
    }
    auto f = heap.top();
    heap.pop();
    auto s = heap.top();
    heap.pop();
    ans = min(ans, (f.first + 1 >> 1) + (s.first + 1 >> 1));
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