#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int ans =1;
    if(a>b)swap(a,b);
    for(int i = a;i < b;i ++ )
    {
        ans *= 32;
    }
    cout<<ans<<endl;
}