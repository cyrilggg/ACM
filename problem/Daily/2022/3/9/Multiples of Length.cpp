/*
    Rating : 1600
    思路： 第一行消掉第一个  第二行乘上 -(n * v[i])  第三行就(n - 1) * v[i]
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

signed main()
{
    int n;
    cin >> n;
    vector<int>v(n + 1);
    for (int i = 1; i <= n; i ++ )  cin >> v[i];
    if (n > 1)
    {
   
    cout << 1 << ' ' << 1 << '\n';
    cout << -v[1] << endl;
    v[1] = 0;
    cout << 1 << ' ' << n << '\n';
    for (int i = 1; i <= n; i ++ )   cout << -(n * v[i]) << ' ';
    
    cout << endl;
    cout << 2 << ' ' << n << '\n';
    for (int i = 2; i <= n; i ++ )  cout << (n - 1) * (v[i]) << ' ';
    cout << endl;
    }
    else
    {
        cout << 1 << ' ' << 1 << '\n' << 0 << '\n' << 1 << ' ' << 1 << '\n' << 0 << '\n' << 1 << ' ' << 1 << '\n' << -v[1];
    }
    return 0;
}