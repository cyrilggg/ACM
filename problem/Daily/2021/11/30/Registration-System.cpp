/*
    Rating : 1300
    ¹şÏ£±íÂãÌâ
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;


signed main()
{
    int t;
    scanf("%d", &t);
    unordered_map<string,int>m;
    while (t -- )
    {
        string a;
        cin >> a;
        if(m.count(a) == 0)
        {
            cout << "OK" << endl;
            m[a] = 0;
        }
        else
        {
            m[a] ++;
            cout << a + to_string(m[a]) << endl;
        }
    }
    return 0;
}