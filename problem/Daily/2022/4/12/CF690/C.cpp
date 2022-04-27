#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    vector<int>v(n);
    priority_queue<int,vector<int>,greater<int>>heap;
    for (int i = 0; i < n; i ++ )
    {
        cin >> v[i];
        heap.push(v[i]);
    }
    sort(v.begin(), v.end())
    int idx = 0;
    int maxn = v[n - 1];
    while (heap.size())
    {
        auto t = heap.top();
        if (t == maxn)
            break;
        heap.pop();
        auto sec = heap.top();
        heap.pop();
        sec += t;
        
    }
    cout << idx << endl;
}

signed main()
{
    int _ = 1;
    cin >> _;
    while ( _-- )solve();
}