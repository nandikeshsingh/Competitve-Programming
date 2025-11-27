#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int maxn=3e5+10;
int n;
vector<int>gp[maxn];
int sbt[maxn];
void dfs(int n,int p)
{
    for(auto& c : gp[n])
    {
        if(c!=p)
        {
            dfs(c,n);
            sbt[n]+=sbt[c];
        }
    }
    sbt[n]++;

}
signed main()
{
    speed;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }
    dfs(1,-1);
    int ans=0;
    int mx=-1e18;
    for(auto& u : gp[1])
    {
        mx=max(mx,sbt[u]);
        ans+=sbt[u];
    }
    cout<<ans-mx+1<<endl;
    return 0;
}


