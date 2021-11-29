#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,k;
    cin>>k>>a>>b;
    long long aa = 0, bb = 0;
    long long t = 1,d = 1;
    for(int i = 0; i <= 17 ; i++ )
    {
        aa+=(a/t)%10*d;
        bb+=(b/t)%10*d;
        t*=10;
        d*=k;
    }
    //cout<<aa<<' '<<bb<<endl;
    cout << aa * bb << endl;
    return 0;
}