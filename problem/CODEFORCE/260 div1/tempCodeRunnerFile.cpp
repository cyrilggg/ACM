#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long a[N],f[N];
int main()
{
    int n;
    cin >> n;
    int maxn = -1;
    for (int i = 0; i < n; i ++ )
    {
        int x;
        cin >> x;
        a[x] ++ ;
        maxn = max(maxn,x);
    }
    f[0] = 0;
    f[1] = a[1];
    for (int i = 2; i <= maxn; i ++)
    {
        f[i] = max(f[i - 1], f[i - 2] + a[i] * i);
    }
    cout<<f[maxn]<<endl;
}