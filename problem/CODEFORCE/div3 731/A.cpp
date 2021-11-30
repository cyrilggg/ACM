#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x[3];
        int y[3];
        for(int i=0;i<3;i++)
            cin>>x[i]>>y[i];
        int res=0;
        if(x[0]==x[1])
            {

                res=abs(y[1]-y[0]);

                if(x[2]==x[1])
                    if(((y[2]>y[1])&&(y[2]<y[0]))||((y[2]<y[1])&&(y[2]>y[0])))
                        {
                            res=res+2;

                        }

            }
        else if(y[0]==y[1])
            {
                res=abs(x[1]-x[0]);
                if(y[2]==y[1]&&(((x[2]>x[1])&&(x[2]<x[0]))||((x[2]<x[1])&&(x[2]>x[0]))))
                    res+=2;


            }
        else    res=abs(x[0]-x[1])+abs(y[0]-y[1]);
        cout<<res<<endl;
    }
    return 0;
}
