#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10, mod = 998244353;
int f[N][10];
int main()
{
    int n,x;
    cin >> n >> x;
    f[1][x] = 1;
    for (int i = 2; i <= n; i ++ )
    {
        cin>>x;
        for(int j = 0; j <= 9; j ++ )
        {
            f[i][(j + x) % 10] = (f[i][(j + x) % 10] + f[i - 1][j]) % mod;
            f[i][(j * x) % 10] = (f[i][(j * x) % 10] + f[i - 1][j]) % mod;
        }
    } 
    for (int i = 0; i <= 9; i ++ )
        cout<<f[n][i]<<endl;
}