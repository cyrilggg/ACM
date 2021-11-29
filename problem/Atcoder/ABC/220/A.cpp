#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>> a>> b>> c;
    if(c>=a && c<= b)cout<<c<<endl;
    else
    {
        int ans = ( a + c-1 )/c * c;
        if (ans > b)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}