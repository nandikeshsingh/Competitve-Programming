#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<int,int>mp;
        for(int i=2;i*i<=n;i++)
        {
            while(n%i==0)
            {
                mp[i]++;
                n/=i;
            }
        }
        if(n>1)mp[n]++;
        int ans=0;
        while(sz(mp))
        {
            int mn=1e18;
            for(auto& u : mp)mn=min(mn,u.second);
            int cur=1;
            vector<int>del;
            for(auto& u : mp)
            {
                cur*=u.first;
                u.second-=mn;
                if(u.second==0)del.push_back(u.first);
            }
            for(auto& u : del)mp.erase(u);
            ans+=(cur*mn);

        }
        cout<<ans<<endl;
    }
    return 0;
}


