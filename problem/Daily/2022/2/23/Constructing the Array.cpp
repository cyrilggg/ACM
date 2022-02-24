/*
    Rating: 1600
    思路： 用堆模拟
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int a[N];
struct Node
{
    int l, r;
    bool operator<(const Node &a) const
    {
        if (a.r - a.l == r - l)
        {
            return l > a.l;
        }
        return r - l < a.r - a.l;
    }
};
void solve()
{
    int n;
    cin >> n;
    priority_queue<Node>q;
    q.push({1, n});
    int edx = 1;
    while (q.size())
    {
        auto tmp = q.top();
        q.pop();
        int idx = tmp.l + tmp.r >> 1;
        a[idx] = edx ++;
        if (tmp.l < idx) q.push({tmp.l, idx - 1});
        if (tmp.r > idx) q.push({idx + 1, tmp.r});
    }
    for (int i = 1; i <= n; i ++ )
        cout << a[i] << ' ';
    cout << endl;
}
 
signed main()
{
    int t;
    cin >> t;
    while (t -- )solve();
    return 0;
}