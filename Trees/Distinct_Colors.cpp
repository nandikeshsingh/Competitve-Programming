#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<vector<int>>gp(n+1);
    vector<int>c(n+1);
    vector<map<int,int>>mp(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        mp[i][c[i]]++;
    }
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        gp[a].push_back(b);
        gp[b].push_back(a);
    }
    vector<int>ans(n+1,0);
    auto dfs=[&](auto self,int node,int par)->void
    {
        for(auto& u : gp[node])
        {
            if(u==par)continue;
            self(self,u,node);
            if(sz(mp[u])>sz(mp[node]))
            {
                swap(mp[u],mp[node]);
                ans[node]=ans[u];
            }
            for(auto&[col,cnt]:mp[u])
            {
                mp[node][col]+=cnt;
            }
        }
        ans[node]=sz(mp[node]);
    };
    dfs(dfs,1,-1);
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
