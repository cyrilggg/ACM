#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
int f[N];
int n;

int sg(int x)
{
    if (f[x] != -1) return f[x];
    unordered_set<int>S;
    
    for (int i = 1; i <= x / i && i < x; i ++ )
    {
        
        if (x % i == 0)
        {
            S.insert(sg(i));
            if (x / i != x) S.insert(sg(x / i));
        }
    }
    int t = 0;
    while (S.count(t)) t ++;
    f[x] = t;
    return t;
}

bool check(vector<int> v)
{
    int x = 0;
    for (int i = 1; i <= n; i ++ )
    {
        x ^= sg(v[i]);
    }
    return x > 0;
}

int main()
{
    memset(f, -1, sizeof f);
    while (cin >> n)
    {
        vector<int> v(n + 1, 0);
        for (int i = 1; i <= n; i ++ )  cin >> v[i];
        if (check(v)) cout << "freda" << endl;
        else cout << "rainbow" << endl;
    }
    return 0;
}