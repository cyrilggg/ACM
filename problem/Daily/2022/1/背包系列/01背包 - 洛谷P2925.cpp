#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;
int f[N];
int main()
{
    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= n; i ++ )
    {
        int w;
        cin >> w ;
        for (int j = m; j >= w; j -- ) f[j] =max(f[j], f[j - w] + w);
    }
    cout << f[m] << endl;
    return 0;
}