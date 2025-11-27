#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    string s;
    cin>>s;
    vector<int>cnt(10);
    map<int,int>mp;
    mp[0]++;
    int ans=0;
    for(auto& u : s)
    {
        int val=u-'0';
        cnt[val]++;
        int mask=0;
        for(int i=0;i<10;i++)
        {
            if(cnt[i]%2)mask+=(1LL<<i);
        }
        ans+=mp[mask];
        mp[mask]++;
    }
    cout<<ans<<endl;
    return 0;
}


