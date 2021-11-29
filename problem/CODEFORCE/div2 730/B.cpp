#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
long long q[N];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;


        long long sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>q[i];
            sum+=q[i];
        }
        if(n==1)cout<<0<<endl;
        else{
        long long ave=sum/n;
        sum-=ave*n;

        long long ans=0;
        ans=sum*(n-sum);
        cout<<ans<<endl;
        }
    }


    return 0;
}



