#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==1)cout<<1<<' '<<0<<endl;
        else
        {
            if(n%3==2)
            cout<<n-(n/3)*2-2<<' '<<n/3+1<<endl;
            else cout<<n-(n/3)*2<<' '<<n/3<<endl;
        }

    }
    return 0;
}
