#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define eb emplace_back
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
        vector<vector<int>>gp(n+1);
        for(int i=1;i<n;i++)
        {
            int u,v;cin>>u>>v;
            gp[u].emplace_back(v);
            gp[v].emplace_back(u);
        }
        int lo=1,hi=n;
        while(lo<hi)
        {
            int mid=(lo+hi+1)>>1;
            int comp=1;
            auto dfs=[&](auto self,int node,int par)->int
            {
                int sz=1;
                for(auto& u : gp[node])
                {
                    if(u==par)continue;
                    sz+=self(self,u,node);

                }
                if(sz>=mid && node!=1)
                {
                    comp++;
                    return 0;
                }
                return sz;
            };
            int sz=dfs(dfs,1,-1);
            if(sz<mid)comp=1;
            if(comp>=k+1)lo=mid;
            else hi=mid-1;
        }
        cout<<lo<<endl;
    }
    return 0;
}
 