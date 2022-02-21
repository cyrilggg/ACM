#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_set>

using namespace std;
map <string, int>f;
int n, m;
int sg(string a)
{
    if(f.count(a))return f[a];
    cout << a << endl;
    unordered_set<int>S;
    for (int i = 1; i < a.size(); i ++ )
    {
        if (a[i] == 'T')
        {
            string b = a;
            int x = i / n, y = i % m;
            for (int j = 1 ; j < i; j ++ )
            {
                if (j / n <= x && j % m <= y)
                {
                    if (a[i] == 'T') a[i] = 'H';
                    else a[i] = 'T';
                }
            }
            S.insert(sg(b));
        }
    }
    int x = 0;
    while (S.count(x)) x ++;
    f[a] = x;
    cout << a << ' ' << x << endl;
    return x;
}

int main()
{
    int t;
    cin >> t;
    while ( t -- )
    {
        cin >> n >> m;
        string s = "a";
        for (int i = 1; i <= n; i ++ )
        {
            string a;
            cin >> a;
            s = s + a;
        }
        if (sg(s))cout << "-_-" << endl;
        else cout << "=_=" << endl;
        
    }
    return 0;
}