#include <bits/stdc++.h>
using namespace std;
const int  N = 2e5 + 10;
string a, b;
int idx[N];

bool check(int x)
{
    set<int>s;
    for (int i = 0; i < x; i ++ )   s.insert(idx[i]);
    for (int i = 0, j = 0; i < a.size(); i ++ )
    {
        if (s.count(i + 1)) continue;
        if (a[i] == b[j])
        {
            j ++ ;
            if (j == b.size()) return true;
        }
    }
    return false;
}

int main()
{
    cin >> a >> b;
    for (int i = 0; i < a.size(); i ++ )    cin >> idx[i];
    int l = 0, r = a.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l - 1 << endl;
}