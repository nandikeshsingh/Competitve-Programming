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
        vector<int>c(n+1,0);
        vector<map<int,int>>mp(n+1);
        for(int i=1;i<=n;i++)cin>>c[i],mp[i][c[i]]++;
        vector<vector<int>>gp(n+1,vector<int>(0));
        for(int i=1;i<n;i++)
        {
            int u,v;cin>>u>>v;
            gp[u].push_back(v);
            gp[v].push_back(u);
        }
        int ans=0;
        auto dfs=[&](auto self,int n,int p)->void
        {   
            for(auto& u : gp[n])
            {
                if(u==p)continue;
                self(self,u,n);
                if(mp[u].count(c[n]))
                {
                    ans+=mp[u][c[n]];
                    mp[u].erase(c[n]);
                }
                if(sz(mp[u])>sz(mp[n]))swap(mp[u],mp[n]);
                for(auto& [col,cnt] : mp[u])
                {
                    ans+=cnt*mp[n][col];
                    mp[n][col]+=cnt;
                }
            }
        };
        dfs(dfs,1,-1);
        cout<<ans<<endl;
    }
    return 0;
}



