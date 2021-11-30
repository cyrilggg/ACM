#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,s,i,j,k;
    cin>>m>>s;
    if(s>m*9||s<1&&m>1)
        cout<<"-1"<<" "<<"-1";
    else
    {
        for(i=m-1,k=s;i>=0;i--)
        {
            int j=max(0,k-9*i); 
            if(j==0&&i==m-1&&k)j=1;
            cout<<j;k-=j;
        }
        cout<<" ";
        for(i=m-1,k=s;i>=0;i--)
        {
            int j=min(9,k);
            cout<<j;k-=j;
        }
    }
    return 0;
}