#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
vector<vector<pair<int,int>>>gp;
multiset<int>xb;
bool ans;
int n,a,b;
void dfsb(int node,int p,int xr)
{
    if(node!=b)xb.insert(xr);
    for(auto& u : gp[node])
    {
        if(u.first==p)continue;
        dfsb(u.first,node,xr^(u.second));
    }
}
void dfs(int node,int p,int xr)
{
    if(node!=b && xb.find(xr)!=xb.end())ans=1;
    else if(node==b)
    {
        if(xr==0)ans=1;
        return;
    }
    for(auto& u : gp[node])
    {
        if(u.first==p)continue;
        dfs(u.first,node,xr^(u.second));
    }
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>a>>b;
        gp.clear();
        xb.clear();
        gp.resize(n+1,vector<pair<int,int>>(0));
        for(int i=1;i<n;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            gp[u].push_back({v,w});
            gp[v].push_back({u,w});
        }
        dfsb(b,-1,0);
        dfs(a,-1,0);
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

