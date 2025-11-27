#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n,q;cin>>n>>q;
    map<int,int>mp;
    for(int i=0;i<q;i++)
    {
        int c;cin>>c;
        mp[c]++;
    }
    int cur=0;
    for(auto& u : mp)
    {
        if(u.second&1)cur++;
    }
    cout<<n-cur<<endl;
    return 0;
}


