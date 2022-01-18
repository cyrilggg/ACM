#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1010;
int f[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
    {
        int w, v;
        cin >> w >> v;
        for (int j = m; j >= w; j -- ) f[j] = max(f[j], f[j - w] + v);
    }
    cout << f[m] << endl;
    return 0;
}