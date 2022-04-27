#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class ATM {
public:
    unordered_map<int,long long>mp;
    vector<int>v;
    ATM() {
        v.push_back(20);
        v.push_back(50);
        v.push_back(100);
        v.push_back(200);
        v.push_back(500);
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0;i<(int)banknotesCount.size();i++){
            mp[v[i]]+=banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<long long>t;
        for(int i=(int)v.size()-1;i>=0;i--){
            long long d=min(mp[v[i]], max(0LL, (long long)amount/v[i]));
            t.push_back(d);
            amount-=d*v[i];
        }
        vector<int>ans;
        if(amount==0){
            for(int i=t.size()-1;i>=0;i--){
                mp[v[(int)t.size()-1-i]]-=t[i];
                ans.push_back(t[i]);
            }
            return ans;
        }
        return {-1};
    }
};