#include <bits/stdc++.h>
using namespace std;
int main(){
    string s1, s2;
    cin>>s1>>s2;
    if(s1!=s2)
        for(int i=0; i<s1.length(); i++)
            if(s1[i]!=s2[i])
                if(s1[i+1]!=s2[i+1]){
                    swap(s2[i],s2[i+1]);
                    break;}
    s1!=s2? cout<<"No" : cout<<"Yes";
    return 0;
}