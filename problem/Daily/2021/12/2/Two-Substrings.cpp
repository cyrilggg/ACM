/*
    Rating : 1500
    感觉还没 1200 的难，直接搜就可以了
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    string a;
    cin >> a;
    bool flag = false;
    int pos = a.find("AB");
    if(pos != a.npos)
    {
        pos = a.find("BA", pos + 2);
        if (pos != a.npos) flag = true;
    }
    pos = a.find("BA");
    if(pos != a.npos)
    {
        pos = a.find("AB", pos + 2);
        if (pos != a.npos) flag = true;
    }
    
    if (flag) puts("YES");
    else puts("NO");
    
    return 0;
}