#include <bits/stdc++.h>
using namespace std;

string a = "0123456789ABCDEF";
string b = "1000101021120100";
int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    vector<char>v;
    while (n)
    {
        v.push_back(a[n % 16]);
        cnt += b[n % 16] - '0';
        n /= 16;
    }
    for (auto vv : v) cout << vv;
    cout << endl;
    cout << cnt << endl;
    return 0;
}