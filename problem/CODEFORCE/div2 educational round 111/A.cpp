
#include<bits/stdc++.h>
using namespace std;

int n;
int ans;
int main()
{
    int t;

    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        int i;
        for(i=1;i*i<n;i++);
        if(i*i==n)ans=i;
        else ans=i;
        cout<<ans<<endl;
    }

    return 0;

}
