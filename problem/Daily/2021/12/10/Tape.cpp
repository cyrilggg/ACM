/*
    Rating : 1400
    按长度进行排序就可以，这里用了优先队列其实没必要，排序就好
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

#define int long long
const int N = 1e5 + 10;
int a[N];
int n, m, k;
bool vis[N];
struct Node
{
    int l;
    int s;
    int e;
    bool operator<(Node b)const
    {
        return l > b.l;
    }
};
signed main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++ )  cin >> a[i];
    int ans = n;
    int idx = 0;
    priority_queue<Node>q;
    for (int i = 1; i < n; i ++ )
    {
        q.push({a[i + 1] - a[i] + 1,i, i + 1});
    }
    while ( n - idx > k && q.size())
    {
        auto t = q.top();
        q.pop();
       // cout << t.l <<' '<<t.s<<' '<<t.e<<endl;
        
        ans += t.l - vis[t.s] - vis[t.e];
        ans -= !vis[t.s] + !vis[t.e];
        idx ++ ;
        vis[t.s] = 1;
        vis[t.e] = 1;
        //cout << ans << ' ' << idx << endl;
    }
    cout << ans << endl;
    return 0;
}
