#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    cin >> a;
    sort(a.begin(),a.end());
    long long x = 0, y = 0, ans = 0;
    for(int i = 1; i <= a.size(); i += 2 )
    {
        x = x * 10 + a[i] - '0';
    }
    for(int i = 0; i <= a.size(); i += 2)
    {
        y = y * 10 + a[i] - '0';
    }
    ans = x * y;
    cout<<x<<' '<<y<<endl;
    cout << ans << endl;

    return 0;
}