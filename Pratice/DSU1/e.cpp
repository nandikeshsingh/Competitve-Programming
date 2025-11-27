#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
vector<vector<int>>gp;
vector<int>tin,tout,p;
int t;
void dfs(int node,int par)
{
    p[node]=par;
    tin[node]=++t;
    for(auto& u : gp[node])
    {
        if(u!=par)
        {
            dfs(u,node);
        }
    }
    tout[node]=++t;
}
bool is_ancestor(pair<int,int>&p1,pair<int,int>&p2)
{
    return (p1.first<=p2.first && p1.second>=p2.second);
}
signed main()
{
    speed;
    int n,m;
    cin>>n>>m;
    tin.resize(n+1,0);
    tout.resize(n+1,0);
    p.resize(n+1,0);
    gp.resize(n+1,vector<int>(0));
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }
    dfs(1,1);

    while(m--)
    {
        int k;
        cin>>k;
        vector<int>vec(k);
        vector<pair<int,int>>has;
        for(int i=0;i<k;i++)
        {
            cin>>vec[i];
            vec[i]=p[vec[i]];
            has.push_back({tin[vec[i]],tout[vec[i]]});
        }
        sort(all(has));
        bool ok=1;
        int len=(int)has.size();
        for(int i=len-2;i>=0;i--)
        {
            if(!is_ancestor(has[i],has[i+1]))
            {
                ok=0;
                break;
            }
        }
        cout<<(ok?"YES":"NO")<<endl;
    }
    return 0;
}