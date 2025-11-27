#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n;cin>>n;
    vector<int>c(n+1);
    vector<map<int,int>>mp(n+1);
    vector<int>ans(n+1),tot(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        mp[i][c[i]]++;
        tot[i]=1;
        ans[i]=c[i];
    }
    vector<vector<int>>gp(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }
    auto dfs=[&](auto self,int node,int par)->void
    {
        int big=-1;
        for(auto& u : gp[node])
        {
            if(u==par)continue;
            self(self,u,node);
            if(big==-1 || sz(mp[u])>sz(mp[big]))big=u;
        }
        if(big!=-1)
        {
            swap(mp[big],mp[node]);
            tot[node]=tot[big];
            ans[node]=ans[big];
        }
        
        for(auto& u : gp[node])
        {
            if(u==par)continue;
            for(auto [col,cnt]: mp[u])
            {
                mp[node][col]+=cnt;
                if(tot[node]<mp[node][col])
                {
                    tot[node]=mp[node][col];
                    ans[node]=col;
                }
                else if(tot[node]==mp[node][col])
                {
                    ans[node]+=col;
                }
            }
            mp[u].clear();      
        }
    };
    dfs(dfs,1,-1);
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}