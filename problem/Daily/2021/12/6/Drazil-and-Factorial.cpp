/*
    Rating : 1400
    可以直接按位构造
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

string ch[10]={"","","2","3","223","5","53","7","7222","7332"};
int main()
{
    string ans;
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ )
    {
        char x;
        cin >> x;
        ans += ch[x - '0'];
    }
    sort (ans.begin(), ans.end());
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
    
    return 0;
}