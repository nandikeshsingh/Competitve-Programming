#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int n;
vector<vector<int>>gp;
vector<int>val;
void dfs(int node,int p)
{
    bool ok=1;
    for(auto& u : gp[node])
    {
        if(u==p)continue;
        dfs(u,node);
        ok&=val[u];
    }
    if(!ok)val[node]=1;
}
signed main()
{
    speed;
    cin>>n;
    gp.resize(n+1,vector<int>(0));
    val.resize(n+1);
    for(int i=1;i<n;i++)
    {
        int a,b;cin>>a>>b;
        gp[a].push_back(b);
        gp[b].push_back(a);
    }
    dfs(1,-1);
    cout<<accumulate(all(val),0LL)<<endl;
    return 0;
}