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
        int n,k;
        cin>>n>>k;
        vector<int>c(n);
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            cin>>c[i];
            mp[c[i]]++;
        }
        multiset<int>mst;
        for(auto& u : mp)
        mst.insert(u.second);
        mst.insert(0);
        while(*prev(mst.end())>=k)
        {
            int l=*prev(mst.end());
            mst.erase(prev(mst.end()));
            int ll=*prev(mst.end());
            mst.erase(prev(mst.end()));
            mst.insert(ll+k-1);
        }
        int ans=0;
        for(auto& u : mst)ans+=u;
        cout<<ans<<endl;
    }
    return 0;
}


