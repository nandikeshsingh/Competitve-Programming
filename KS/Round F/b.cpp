#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
// #define int long long
vector<vector<int>>gp;
vector<int>depth;
void dfs(int node,int par,int d)
{
    depth[node]=d;
    for(auto& u : gp[node])
    {
        if(u==par)continue;
        dfs(u,node,d+1);
    }
}
signed main()
{
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        int n,q;
        cin>>n>>q;
        gp.resize(n+1,vector<int>(0));
        depth.resize(n+1);
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            gp[u].push_back(v);
            gp[v].push_back(u);
        }
        int tot=q;
        while(q--)
        {
            int x;cin>>x;
        }
        dfs(1,-1,1);
        int ans=0;
        map<int,int>mp;
        for(int i=1;i<=n;i++)mp[depth[i]]++;
        for(auto& u : mp)
        {
            if(u.second<=tot)
            {
                ans+=u.second;
                tot-=u.second;
            }
            else break;
        }
        cout<<"Case #"<<c<<": "<<ans<<endl;
    }
  
    return 0;
}