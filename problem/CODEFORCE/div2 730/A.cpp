#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long a,b;
        cin>>a>>b;
        if(a==b)
            cout<<"0 0"<<endl;
        else if(abs(a-b)==1)cout<<"1 0"<<endl;
        else
        {
            long long min1;
            long long exm=max(a,b)-min(a,b);



                long long stepad=a%exm;
                long long stepbd=b%exm;
                long long stepau=exm-(a%exm);
                long long stepbu=exm-(b%exm);


                min1=min(min(stepad,stepbd),min(stepau,stepbu));

            cout<<exm<<' '<<min1<<endl;

        }
    }
    return 0;
}
